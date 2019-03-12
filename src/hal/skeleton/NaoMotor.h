//
// Created by Flotschi on 02/01/2019.
//

#ifndef DUCKBURG_NAOMOTOR_H
#define DUCKBURG_NAOMOTOR_H

#include <map>
#include <string>
#include <vector>

namespace skeleton {
    class NaoMotor {
    public:
        NaoMotor(std::string name);
        //normal functions to call the motors
        void interpolation(const std::vector<float> &angles, const std::vector<float> &times, bool isAbsolute);
        void interpolationWithSpeed(const std::vector<float> &angles, float velocity);
        void interpolationBezier( const std::vector<float> angles, const std::vector<float> &times);
        void setAngles(const std::vector<float> &angles, float velocity);
        void changeAngles(const std::vector<float> &changes, float velocity);
        //with only one value in the parameters
        void interpolation_OneValue(float angle, float time);
        void interpolationWithSpeed_OneValue(float angle, float time, float velocity);
        void interpolationBezier_OneValue(float angle, float time);
        void setAngles_OneValue(float angle, float velocity);
        void changeAngles_OneValue(float change, velocity);
        std::vector<float> getAngles(bool useSensors);
		bool areResourcesAvailable();
		void killAllTasks();
    private:
        std::string name;
        std::vector<float> getVector(float value);
    };

    std::map <std::string, NaoMotor> motorCollection;
    void openMotorFile();
    void initMotors();
}

#endif //DUCKBURG_NAOMOTOR_H
