#include <utility>

//
// Created by obyoxar on 17.09.18.
//

#include <iostream>
#include <chrono>
#include "Brain.h"
#include "../hightools/Dyllo.h"
#include "../engines/ExampleEngine.h"
#include "Intent.h"
#include "StandardIntents.h"
#include "../hightools/TimeUtil.h"
#include "Logger.h"
#include <chrono>
#include <fstream>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <vector>

#undef LOG_SOURCE
#define LOG_SOURCE "MyBrain"

#define LOG_TAG LOGGER(Brain)

IMPLEMENT_SINGLETON(Brain)


//<editor-fold desc="lifecycle">
void Brain::run() {
    LINFO("Brain is now running")
    assert(!this->_shouldBeRunning);
    this->_shouldBeRunning = true;
    this->issueIntent(INTENTID_ON_BRAIN_RUN, nullptr);

    while(this->_shouldBeRunning){
        long startTime = timeutil::getCurrentTimeNanos();
        this->manualTick(startTime, startTime+100*1000*1000);
    }
    LINFO("Brain is no longer running");
}

void Brain::manualTick(long startTimeNanos, long endTimeNanos) {
    Intent(INTENTID_ON_BRAIN_TICK, nullptr).issue();
    //std::cout << startTimeNanos << std::endl;
    while(!this->intent_buffer.empty() && this->intent_buffer.top()->executeAt() <= static_cast<unsigned long>(startTimeNanos)){
        Intent* intent = this->intent_buffer.top();
        this->dispatchIntent(*intent);
        this->intent_buffer.pop();
        delete intent;
    }
    while(!this->intent_buffer_later.empty() &&
            timeutil::getCurrentTimeNanos() < endTimeNanos){
        Intent* intent = this->intent_buffer_later.front();
        this->dispatchIntent(*intent);
        this->intent_buffer_later.pop();
        delete intent;
    }
}

void Brain::init() {
    assert(!this->_isInitialized);
    LINFO("Brain is being initialized")
    this->_isInitialized = true;
    Brain::getInstance(); //TODO Find out: For gods sake why???
}

void Brain::shutdown() {
    LINFO("Brain is now shutting down");

    this->_shouldBeRunning = false;
    this->_isStopped = true;
    Intent(INTENTID_ON_BRAIN_SHUTDOWN, nullptr).issue();
    LINFO("Brain shutdown finished");
}
//</editor-fold>
void Brain::loadEngines(std::istream & recipe) {    //TODO UNTESTED
    LINFO("Loading Engines...")
    using boost::property_tree::ptree;
    ptree pt;
    read_xml(recipe, pt);
    ptree &tree = pt.get_child("ENGINES");
    for(auto v: tree){
        if(v.first == "ENGINE"){
            std::string fileName;
            try{
                fileName = v.second.get<std::string>("FILENAME");
            }
            catch(boost::property_tree::ptree_bad_path&){
                std::stringstream fN;
                fN << v.second.get<std::string>("NAME") << ".so";
                fileName = fN.str();
            }
            try{
                auto name = v.second.get<std::string>("NAME");
                LFINFO("Loading: '" << name << "' from '" << fileName << "'");
                auto engine = dl_load_class<EngineBase>(fileName,name);
                int enBaseVersion = engine->getEngineBaseVersion();
                if(enBaseVersion != ENGINE_BASE_VERSION) {
                    throw std::runtime_error("Could not load '" + name + "' because "
                                             "it was compiled against an older version of Duckburg. "
                                             "Wanted: V" + std::to_string(ENGINE_BASE_VERSION) +
                                             " Got: V"+std::to_string(enBaseVersion));
                }
                auto props = v.second.get_child_optional("PROPERTIES");
                if(props){
                    LFINFO("Found Engine-Specific properties!");
                    engine->setProperties(*props);
                }else{
                    engine->setProperties(boost::property_tree::ptree());
                }
                registerEngine(engine);
            }
            catch(std::runtime_error& err){
                std::string importance;
                try{
                    importance = v.second.get<std::string>("IMPORTANCE");
                }
                catch(boost::property_tree::ptree_bad_path&){
                    importance = "SOFT";
                }
                if(importance=="REQUIRED"){
                    std::stringstream msg;
                    msg << "Required Engine " << v.second.get<std::string>("NAME") << " in File "
                        << v.second.get<std::string>("FILENAME") << " not found. Error was:\n"
                        << err.what() << std::endl;
                    throw std::runtime_error(msg.str());
                }
                else if(importance=="SOFT"){
                    LFWARN("Soft Engine " << v.second.get<std::string>("NAME")
                            << " in File " << v.second.get<std::string>("FILENAME") << " not found. Error was:\n"
                            << err.what());
                }
                else{
                    std::stringstream msg;
                    msg << "Importance of Engine " << v.second.get<std::string>("NAME") << " in File "
                        << v.second.get<std::string>("FILENAME") << " unknown. Error was:\n"
                        << err.what() << std::endl;
                    throw std::runtime_error(msg.str());
                }
            }
        }
    }
    LINFO("Brain has finished loading Engines");
    //auto engine = dl_load_class<EngineBase>(libnamestream.str(), "ExampleEngine");
}

void Brain::addDispatcher(Intent::event_id id, event_handler listener, order_type type) {
    this->eventDispatchers[id][type].connect(listener);
}

void Brain::registerEngine(EngineBase *engine) {
    engines.push_back(engine);
    LFINFO("Loaded Engine with internal name '" << engine->getName() << "'");
    engine->onLoad();
}

//<editor-fold desc="issueIntent">
[[deprecated("Use Intent(...).issue()")]]
void Brain::issueIntent(Intent::event_id id, void *data) {
    Intent intent(std::move(id), data);
    issueIntent(intent);
}

void Brain::loadEngines(std::string filename) {
    LFINFO("Opening Recipe file: '" << filename << "'");
    std::ifstream conf (filename);
    this->loadEngines(conf);
}

void Brain::issueIntent(Intent &intent) {
    intentIssued(&intent);
    if(intent.executeAt() == INTENT_IMMEDIATE) {    //Intent is dispatched immediately
        this->dispatchIntent(intent);
    }else if(intent.executeAt() == INTENT_LATER){   //Intent waits until a specific point
        this->intent_buffer_later.push(new Intent(intent));
    }else{
        this->intent_buffer.push(new Intent(intent));   //Intent gets dispatched when possible
    }
}
//</editor-fold>

//<editor-fold desc="dispatchIntent">
void Brain::dispatchIntent(Intent &intent) {
    intentDispatched(&intent);
    if(!this->eventFilters(&intent)){
        return;
    }

    //TODO is the unused-slot-removal really better?

    auto intentDisp = &this->eventDispatchers[intent.id()];
    bool empty = true;
    for (unsigned long i = SlotOrder::PRE; i <= SlotOrder::POST; ++i) {
        auto disp = &intentDisp->operator[](i);
        empty = empty && disp->empty();
        disp->operator()(intent.data());
    }
    if(empty){
        this->eventDispatchers.erase(intent.id());
    }

}
//</editor-fold>

//<editor-fold desc="MetaIntents">
void Brain::intentIssued(Intent *intent) {
    if(intent->id() == INTENTID_ON_INTENT_ISSUED ||
    intent->id() == INTENTID_ON_INTENT_DISPATCHED ||
    intent->id() == INTENTID_ON_BRAIN_TICK){
        return;
    }
    Intent(INTENTID_ON_INTENT_ISSUED, static_cast<void*>(intent), INTENT_IMMEDIATE).issue();
}

void Brain::intentDispatched(Intent *intent) {
    if(intent->id() == INTENTID_ON_INTENT_ISSUED ||
       intent->id() == INTENTID_ON_INTENT_DISPATCHED ||
       intent->id() == INTENTID_ON_BRAIN_TICK){
        return;
    }
    Intent(INTENTID_ON_INTENT_DISPATCHED, static_cast<void*>(intent), INTENT_IMMEDIATE).issue();
}
//</editor-fold>


void Brain::addFilter(Brain::event_filter filter) {
    this->eventFilters.connect(filter);
}

bool Brain::isStopped() const {
    return _isStopped;
}

void Brain::debugBrain() {
    for(const auto & entry : this->eventDispatchers){
        LFINFO(entry.first << ":")
        for(const auto& slot : entry.second){
            LFINFO(slot.num_slots())
        }
    }
}

#undef LOG_TAG
#define LOG_TAG LOGGER(Intent)

//---------------------------------------//
//---------------INTENT------------------//
//---------------------------------------//

Intent::Intent(Intent::event_id id, void *data, unsigned int delayMillis) :
_id(std::move(id)), _data(data) {
    //TODO This code will not work if an intent is issued with delayMillis=1 or delayMillis=0 when a new epoch of time starts.
    if(delayMillis == INTENT_IMMEDIATE){
        _executeAt = INTENT_IMMEDIATE;
    }else if(delayMillis == INTENT_LATER) {
        _executeAt = INTENT_LATER;
    }else{
        _executeAt = static_cast<unsigned long>(timeutil::getCurrentTimeNanos()) + delayMillis*1000*1000;
    }
}

const Intent::event_id Intent::id() const {
    return _id;
}

void *Intent::data() {
    return _data;
}

void Intent::issue() {
    Brain::getInstance()->issueIntent(*this);
}

unsigned long Intent::executeAt() const{
    return _executeAt;
}
