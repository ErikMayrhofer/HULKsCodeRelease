#include <iostream>
#include <csignal>
#include "../core/Brain.h"
#include "../core/Memory.h"
#include "../core/Logger.h"

#define LOG_TAG LOGGER(main.cpp)

void terminate(int sigcode){
    LFINFO("Received Terminate(" << sigcode << ")")
    Brain::getInstance()->shutdown();
    LFINFO("Shutdown complete.")
}

int main() {
    signal(SIGTERM, terminate);
    signal(SIGINT, terminate);

    Brain::getInstance()->init();
    Brain::getInstance()->loadEngines();
    Brain::getInstance()->run();

#ifdef DEBUG_BRAIN
    LINFO("Brain-Slots-Left: ")
    Brain::getInstance()->debugBrain();
#endif

    LFINFO("Closed gracefully");
    return 0;
}
