//
// Created by obyoxar on 27/11/18.
//

#ifndef DUCKBURG_LOGGINGENGINE_H
#define DUCKBURG_LOGGINGENGINE_H


#include "../core/EngineBase.h"

class LoggingEngine : public EngineBase {

public:
    const char *getName() override;

    void onLoad() override;

    void log(void* data);

    unsigned int getEngineBaseVersion() override;
};


#endif //DUCKBURG_LOGGINGENGINE_H
