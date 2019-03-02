//
// Created by obyoxar on 18/10/18.
//

#ifndef DUCKBURG_BETTERCHRONO_H
#define DUCKBURG_BETTERCHRONO_H

#include <chrono>

namespace timeutil{
    inline long getCurrentTimeNanos(){
        return std::chrono::system_clock::now().time_since_epoch().count();
    }

    inline long getCurrentTimeMillis(){
        return getCurrentTimeNanos()/1000;
    }
}

#endif //DUCKBURG_BETTERCHRONO_H
