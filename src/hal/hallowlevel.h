#ifndef DUCKBURG_HALLOWLEVEL_H
#define DUCKBURG_HALLOWLEVEL_H

#include <utility>

#include <cstring>
#include <vector>

#include <iostream>
#include <alproxies/almotionproxy.h>
#include <qi/os.hpp>
#include <alvalue/alvalue.h>

namespace hallowlevel {
    AL::ALMotionProxy motion("127.0.0.1");

    /**
     * http://doc.aldebaran.com/2-1/naoqi/motion/control-joint-api.html#ALMotionProxy::angleInterpolation__AL::ALValueCR.AL::ALValueCR.AL::ALValueCR.bCR
     * @param motorName name of the motor
     * @param angles list of positions motor will move to
     * @param times timestamps motor will finish movements
     * @param isAbsolute true if absolute change, false if relative
     */
    void motorInterpolation(const std::string &motorName, const std::vector<float> &angles, const std::vector<float> &times, bool isAbsolute);

    /**
     * http://doc.aldebaran.com/2-1/naoqi/motion/control-joint-api.html#ALMotionProxy::angleInterpolationWithSpeed__AL::ALValueCR.AL::ALValueCR.floatCR
     * @param motorName name of the motor
     * @param angles list of positions motor will move to
     * @param velocity speed at which motor turns
     */
    void motorInterpolationWithSpeed(const std::string &motorName, const std::vector<float> &angles, float velocity);

    /**
     * http://doc.aldebaran.com/2-1/naoqi/motion/control-joint-api.html#ALMotionProxy::angleInterpolationBezier__std::vector:ss:CR.AL::ALValueCR.AL::ALValueCR
     * @param motorName name of the motor
     * @param angles list of positions motor will move to
     * @param times timestamps motor will finish movements
     */
    void motorInterpolationBezier(std::string motorName, const std::vector<float> &angles, const std::vector<float> &times);

    /**
     * http://doc.aldebaran.com/2-1/naoqi/motion/control-joint-api.html#ALMotionProxy::setAngles__AL::ALValueCR.AL::ALValueCR.floatCR
     * @param motorName name of the motor
     * @param angles list of positions motor will move to
     * @param velocity speed at which motor turns
     */
    void motorSetAngles(const std::string &motorName, const std::vector<float> &angles,float velocity);

    /**
     * http://doc.aldebaran.com/2-1/naoqi/motion/control-joint-api.html#ALMotionProxy::changeAngles__AL::ALValueCR.AL::ALValueCR.floatCR
     * @param motorName name of the motor
     * @param changes change of motor position to current position
     * @param velocity speed at which motor turns
     */
    void motorChangeAngles(const std::string &motorName, const std::vector<float> &changes,float velocity);

    /**
     * http://doc.aldebaran.com/2-1/naoqi/motion/control-joint-api.html#ALMotionProxy::getAngles__AL::ALValueCR.bCR
     * @param motorName name of the motor
     * @param useSensors true if wanting actual position, false if wanting position predicted by NAOqi
     * @return list of angles in radians
     */
    std::vector<float> motorGetAngles(const std::string &motorName,bool useSensors);

    /**
     * http://doc.aldebaran.com/2-1/naoqi/motion/tools-motion-task-api.html?highlight=almotion#ALMotionProxy::getTaskList
     * @return ids of all tasks
     */
    std::vector<int32_t> getTaskList();

    /**
     * http://doc.aldebaran.com/2-1/naoqi/motion/tools-motion-task-api.html?highlight=almotion#ALMotionProxy::areResourcesAvailable__std::vector:ss:CR
     * @param resourceNames names of joints to check
     * @return true if resources are available
     */
    //implement in NaoMotor
    bool areResourcesAvailable(const std::vector<std::string>& resourceNames);

    /**
     * http://doc.aldebaran.com/2-1/naoqi/motion/tools-motion-task-api.html?highlight=almotion#ALMotionProxy::killTask__iCR
     * @param taskID ID of task to cancel
     * @return true if successfull cancelled
     */
    bool killTask(const int& taskID);

    /**
     * http://doc.aldebaran.com/2-1/naoqi/motion/tools-motion-task-api.html?highlight=almotion#ALMotionProxy::killTasksUsingResources__std::vector:ss:CR
     * @param resourceNames names of joints to kill tasks
     */
    //implement in NaoMotor
    void killTasksUsingResources(const std::vector<std::string>& resourceNames);

    /**
     * http://doc.aldebaran.com/2-1/naoqi/motion/tools-motion-task-api.html?highlight=almotion#ALMotionProxy::killAll
     */
    void killAll();
}

#endif