//
// Created by Flotschi on 15/01/2019.
//

#ifndef DUCKBURG_NAOSENSORS_H
#define DUCKBURG_NAOSENSORS_H
#include <boost/signal.hpp>
#include <boost/bind.hpp>
#include <alproxies/altouchproxy.h>
#include <alvalue/alvalue.h>

namespace skeleton {
    class NaoSensors {
    public:
        void receivedFrontTactilHead();
        void receivedMiddleTactilHead();
        void receivedRearTactilHead();
        void receivedHandRightLeft();
        void receivedHandRightBack();
        void receivedHandRightRight();
        void receivedHandLeftLeft();
        void receivedHandLeftRight();
        void receivedHandLeftBack();
        void receivedRightBumper();
        void receivedLeftBumper();
        void receivedBackBumper();
    private:
        NaoSensors instance;
    };

}
#endif //DUCKBURG_NAOSENSORS_H
