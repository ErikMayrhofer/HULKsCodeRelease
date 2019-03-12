//
// Created by max on 1/2/19.
//
#include "hallowlevel.h"

namespace hallowlevel {

//<editor-fold desc="Motors">
    void motorInterpolation(const std::string &motorName, const std::vector<float> &angles, const std::vector<float> &times, bool isAbsolute) {

        motion.setStiffnesses(motorName,1.0f);
        motion.angleInterpolation(motorName, angles, times, isAbsolute);
    }

    void motorInterpolationWithSpeed(const std::string &motorName, const std::vector<float> &angles, float velocity) {

        motion.setStiffnesses(motorName,1.0f);
        motion.angleInterpolationWithSpeed(motorName, angles, velocity);
    }

    void motorInterpolationBezier(std::string motorName, const std::vector<float> &angles, const std::vector<float> &times) {

        motion.setStiffnesses(motorName,1.0f);
        motion.angleInterpolationBezier({std::move(motorName)}, times, angles);
    }

    void motorSetAngles(const std::string &motorName, const std::vector<float> &angles,float velocity) {

        motion.setStiffnesses(motorName,1.0f);
        motion.setAngles(motorName,angles,velocity);
    }

    void motorChangeAngles(const std::string &motorName, const std::vector<float> &changes,float velocity) {

        motion.setStiffnesses(motorName,1.0f);
        motion.changeAngles(motorName, changes, velocity);
    }

    std::vector<float> motorGetAngles(const std::string &motorName,bool useSensors) {
        std::vector<float> positions = motion.getAngles(motorName, useSensors);
        return positions;
    }
//</editor-fold>

//<editor-fold desc="taskKiller">
    std::vector<int32_t> getTaskList(){
        AL::ALValue motions  =motion.getTaskList();
        std::vector<int32_t> ids;
        int size = motions.getSize();
        for(int i = 0;i<size;i++){
            ids[i] = motions[i][1];
        }
        return ids;
    }

    bool areResourcesAvailable(const std::vector<std::string>& resourceNames){
        return motion.areResourcesAvailable(resourceNames);
    }

    bool killTask(const int& taskID){
        motion.killTask(taskID);
    }

    void killTasksUsingResources(const std::vector<std::string>& resourceNames){
        motion.killTasksUsingResources(AL::ALValue::array(resourceNames));
    }

    void killAll(){
        motion.killAll();
    }
//</editor-fold>
}