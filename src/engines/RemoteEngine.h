//
// Created by ZekReshi on 06.11.2018.
//

#ifndef DUCKBURG_REMOTEENGINE_H
#define DUCKBURG_REMOTEENGINE_H

#include "../core/EngineBase.h"
#include "../core/Intent.h"
#include "boost/lockfree/queue.hpp"

class RemoteEngine : public EngineBase {
public:
    const char *getName() override;

    void onLoad() override;

    unsigned int getEngineBaseVersion() override;

    bool isRunning();

private:
    bool _isRunning = false;
    void onPrint(void* data);
    void onRun(void* data);
    void startServer();
    void issueIntent(void* data);
    boost::lockfree::queue<Intent*> intents{10};
};

#endif //DUCKBURG_REMOTEENGINE_H
