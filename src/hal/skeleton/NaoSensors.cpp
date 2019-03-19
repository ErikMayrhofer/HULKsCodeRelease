//
// Created by Flotschi on 15/01/2019.
//

#include "NaoSensors.h"
#include <boost/signal.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include "../hallowlevel.h"

skeleton::NaoSensors::NaoSensors(){
    AlTouchProxy::FrontTactilTouched().connect(bind(&NaoSensors::receivedFrontTacticalHead, this));
    AlTouchProxy::MiddleTactilTouched().connect(bind(&NaoSensors::receivedMiddleTactilHead, this));
    AlTouchProxy::RearTactilTouched().connect(bind(&NaoSensors::receivedRearTactilHead, this));

    AlTouchProxy::HandLeftBackTouched().connect(bind(&NaoSensors::receivedHandLeftBack, this));
    AlTouchProxy::HandLeftLeftTouched().connect(bind(&NaoSensors::receivedHandLeftLeft, this));
    AlTouchProxy::HandLeftRightTouched().connect(bind(&NaoSensors::receivedHandLeftRight, this));

    AlTouchProxy::HandRightBackTouched().connect(bind(&NaoSensors::receivedHandRightBack, this));
    AlTouchProxy::HandRightLeftTouched().connect(bind(&NaoSensors::receivedHandRightLeft, this));
    AlTouchProxy::HandRightRightTouched().connect(bind(&NaoSensors::receivedHandRightRight, this));

    AlTouchProxy::BackBumperTouched().connect(bind(&NaoSensors::receivedBackBumper, this));
    AlTouchProxy::LeftBumperTouched().connect(bind(&NaoSensors::receivedLeftBumper, this));
    AlTouchProxy::RightBumperTouched().connect(bind(&NaoSensors::receivedRightBumper, this));
}


//sends data to the TouchSensorEngine
void skeleton::NaoSensors::receivedFrontTacticalHead() {
    hallowlevel::SensorEvents::FrontTacticalHeadTriggered();
}
void skeleton::NaoSensors::receivedMiddleTactilHead() {
    hallowlevel::SensorEvents::MiddleTactilHeadTriggered();
}
void skeleton::NaoSensors::receivedRearTactilHead(){
    hallowlevel::SensorEvents::RearTactilHeadTriggered();
}
void skeleton::NaoSensors::receivedHandRightLeft(){
    hallowlevel::SensorEvents::HandRightLeftTriggered();
}
void skeleton::NaoSensors::receivedHandRightBack(){
    hallowlevel::SensorEvents::HandRightRightTriggered();
}
void skeleton::NaoSensors::receivedHandRightRight(){
    hallowlevel::SensorEvents::HandRightBackTriggered();
}
void skeleton::NaoSensors::receivedHandLeftLeft(){
    hallowlevel::SensorEvents::HandLeftLeftTriggered();
}
void skeleton::NaoSensors::receivedHandLeftRight(){
    hallowlevel::SensorEvents::HandLeftRightTriggered();
}
void skeleton::NaoSensors::receivedHandLeftBack(){
    hallowlevel::SensorEvents::HandLeftBackTriggered();
}
void skeleton::NaoSensors::receivedRightBumper(){
    hallowlevel::SensorEvents::RightBumperTriggered();
}
void skeleton::NaoSensors::receivedLeftBumper(){
    hallowlevel::SensorEvents::LeftBumperTriggered();
}

void skeleton::NaoSensors::receivedBackBumper(){
    hallowlevel::SensorEvents::BackBumperTriggered();
}