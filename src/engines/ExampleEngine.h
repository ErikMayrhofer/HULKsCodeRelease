//
// Created by obyoxar on 09/10/18.
//

#ifndef DUCKBURG_EXAMPLEENGINE_H
#define DUCKBURG_EXAMPLEENGINE_H

#include "../core/EngineBase.h"

class ExampleEngine : public EngineBase {
public:
    const char* getName() override;

    void doThing(void* data);

    void onLoad() override;

    unsigned int getEngineBaseVersion() override;

private:
};



#endif //DUCKBURG_EXAMPLEENGINE_H
