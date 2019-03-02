//
// Created by obyoxar on 27/11/18.
//

#include "LoggingEngine.h"
#include "../core/Brain.h"
#include "../core/Logger.h"
#include "../hightools/Dyllo.h"

#define LOG_TAG LOGGER(LoggingEngine)

const char *LoggingEngine::getName() {
    return "LoggingEngine";
}

void LoggingEngine::onLoad() {
    Brain::getInstance()->addDispatcher(INTENTID_ON_INTENT_ISSUED, BINDTHIS(LoggingEngine::log));
}

void LoggingEngine::log(void *data) {
    auto * intent = static_cast<Intent*>(data);

    LFINFO("Intent was issued, will be executed at '" << intent->executeAt() << "'. ID: '" << intent->id() << "'");
}

unsigned int LoggingEngine::getEngineBaseVersion() {
    return ENGINE_BASE_VERSION;
}

DL_CLASS_PUBLISH(LoggingEngine)