//
// Created by obyoxar on 17.09.18.
// This file was the first file ever created! Here everything started.
//

#ifndef DUCKBURG_BRAIN_H
#define DUCKBURG_BRAIN_H


#include <boost/function.hpp>
#include <boost/fusion/container/map.hpp>
#include <boost/signals2/signal.hpp>
#include <unordered_map>
#include <array>
#include "../hightools/BetterClass.h"
#include "EngineBase.h"
#include <iostream>
#include <queue>

#define INTENT_IMMEDIATE 0
#define INTENT_LATER 1
#define BINDTHIS(thisfunction) boost::bind(&thisfunction, this, _1)

#define INTENTID_ON_INTENT_ISSUED "BRNINTENTISSUED"
#define INTENTID_ON_INTENT_DISPATCHED "BRNINTENTDISPATCHED"
#define INTENTID_ON_BRAIN_TICK "BRNNEXTTICK"
#define INTENTID_ON_BRAIN_SHUTDOWN "BRNSHUTDOWN"
#define INTENTID_ON_BRAIN_RUN "BRNSTRTRUNNING"

using namespace boost::fusion;

enum SlotOrder : short int{
    PRE = 0,
    EXEC = 1,
    POST = 2,
};

class Intent {
public:
    typedef std::string event_id;

    Intent(event_id id, void* data, unsigned int delayMillis = INTENT_IMMEDIATE);

    const event_id id() const;
    void * data();

    unsigned long executeAt() const;
    void issue();

private:
    event_id _id;
    void * _data;
    unsigned long _executeAt = 0; //Nanos
};

/***
 * A Comparator for Intents
 */
struct CompareIntentByExecution
{
    /***
     * @param lhs Left Intent
     * @param rhs Right Intent
     * @return true if Left Intent executes before right Intent
     */
    bool operator()(const Intent* lhs, const Intent* rhs) const
    {
        return lhs->executeAt() < rhs->executeAt();
    }
};
/***
 * An operator for checking if every an Intent has passed every filter
 */
struct event_cancellable
{
    typedef bool result_type; //Needed for boost
    /***
     * @tparam InputIterator
     * @param first
     * @param last
     * @return true if ALL event_filter methods returned true
     */
    template<typename InputIterator>
    result_type operator()(InputIterator first, InputIterator last) const
    {
        if (first == last)
            return true;

        bool ret = *first++;
        while (first != last) {
            ret = ret && *first;
            ++first;
        }

        return ret;
    }
};

class Brain {
SINGLETON(Brain)

public:
    typedef void event_handler_rawfunctiontype(void*);
    typedef bool event_filter_rawfunctiontype(Intent* const);
    typedef boost::function<event_handler_rawfunctiontype> event_handler;
    typedef boost::function<event_filter_rawfunctiontype> event_filter;
    typedef boost::signals2::signal<event_handler_rawfunctiontype> event_slot;
    typedef boost::signals2::signal<event_filter_rawfunctiontype, event_cancellable> event_filters;
    typedef SlotOrder order_type;

public:
    void init();
    void run();
    /***
     * A method that specifies a Tick of the brain with a specified timespan
     * @param startTimeNanos The starting Point of the Tick
     * @param endTimeNanos The point in time when the Tick ends (most of the time its startTime + something)
     */
    void manualTick(long startTimeNanos, long endTimeNanos);

    /***
     * A testing method for manually creating an Engine Subclass and registering it
     * Usually this is done automatically by loadRecipe
     * @param engine
     */
    void registerEngine(EngineBase* engine);

    /***
     * Subscribes an Intent to a Slot
     * @param id of the Intent that wants to subscribe
     * @param listener The callback method (use bindThis for this)
     * @param type Speficies if the Intent subscribes to the PRE EXEC or POST subslot
     */
    void addDispatcher(Intent::event_id id, event_handler listener, order_type type = SlotOrder::EXEC);

    /***
     * Adds a new Filter
     * @param filter
     */
    void addFilter(event_filter filter);

    /***
     * Issue a new Intent
     * @param id
     * @param data
     * @deprecated use {@link Intent::issue}
     */
    void issueIntent(Intent::event_id id, void* data);

    /***
     * Issue an existing Intent
     * @param intent
     * @attention all C++ programmers! Please do not use this method, it should only be used internally
     */
    void issueIntent(Intent& intent);

    /***
     * Load specified Engines from a config file
     * @param filename Is conf.xml by default
     */
    void loadEngines(std::string filename = "conf.xml");

    /***
     * This method is called by the loadEngines above and contains the logic for loading the Engines
     * @param recipe
     */
    void loadEngines(std::istream & recipe);

    /***
     * Stops the brain
     */
    void shutdown();

    bool isStopped() const;

    /***
     * Prints all subscribed Intents and their attributes
     */
    void debugBrain();

private:
    void dispatchIntent(Intent& intent);
    bool _shouldBeRunning = false;
    bool _isInitialized = false;
    bool _isStopped = false;

    void intentIssued(Intent* intent);
    void intentDispatched(Intent* intent);

    std::unordered_map<Intent::event_id, std::array<event_slot, 3>> eventDispatchers;
    event_filters eventFilters;
    std::vector<EngineBase*> engines;
    std::priority_queue<Intent*, std::vector<Intent*>, CompareIntentByExecution> intent_buffer;
    std::queue<Intent*> intent_buffer_later;
};

#endif //DUCKBURG_BRAIN_H
