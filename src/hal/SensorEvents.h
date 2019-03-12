//
// Created by Flotschi on 16/01/2019.
//

#ifndef DUCKBURG_SENSOREVENTS_H
#define DUCKBURG_SENSOREVENTS_H

#include <boost/signal.hpp>
#include <boost/bind.hpp>
#include <alproxies/altouchproxy.h>
#include <alvalue/alvalue.h>

namespace hallowlevel {

    class SensorEvents {
        public:
            signal<void> FrontTactilHeadTriggered;
            signal<void> MiddleTactilHeadTriggered;
            signal<void> RearTactilHeadTriggered;
            signal<void> HandRightLeftTriggered;
            signal<void> HandRightRightTriggered;
            signal<void> HandRightBackTriggered;
            signal<void> HandLeftLeftTriggered;
            signal<void> HandLeftRightTriggered;
            signal<void> HandLeftBackTriggered;
            signal<void> RightBumperTriggered;
            signal<void> LeftBumperTriggered;
            signal<void> BackBumperTriggered;
    };
}


#endif //DUCKBURG_SENSOREVENTS_H
