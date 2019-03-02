//
// Created by obyoxar on 09/10/18.
//

#include <boost/signals2/signal.hpp>
#include <iostream>
#include "ExampleEngine.h"
#include "../hightools/Dyllo.h"
#include "../core/Brain.h"
#include "../core/Logger.h"



#define LOG_TAG LOGGER(ExampleEngine)

void ExampleEngine::onLoad() {
    LINFO("Helloooo");
    Brain::getInstance();

    Brain::getInstance()->addDispatcher(INTENTID_ON_BRAIN_TICK, BINDTHIS(ExampleEngine::doThing));

    LFINFO("Config: " << this->config->get<int>("TEST", 32));
    LFINFO("Config: " << this->config->get<int>("YEET", 32));
}

void ExampleEngine::doThing(UNUSED void* data) {
    LDEBUG("Thing is done");
}

const char *ExampleEngine::getName() {
    return "ExampleEngine";
}

unsigned int ExampleEngine::getEngineBaseVersion() {
    return ENGINE_BASE_VERSION;
}

DL_CLASS_PUBLISH(ExampleEngine)
