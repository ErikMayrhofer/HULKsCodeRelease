//
// Created by Flotschi on 02/01/2019.
//

#include "NaoMotor.h"
#include "../hallowlevel.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <utility>
#include <map>
#define   FILENAME "motornames.txt"

using namespace hallowlevel;

skeleton::NaoMotor::NaoMotor(std::string name){
    this->name = name;
}

//normal functions to call the motors
void skeleton::NaoMotor::interpolation(const std::vector<float> &angles, const std::vector<float> &times, bool isAbsolute) {
    motorInterpolation(this->name, &angles, &times,  isAbsolute);
}

void skeleton::NaoMotor::interpolationWithSpeed(const std::vector<float> &angles, float velocity) {
    motorInterpolationWithSpeed(this->name, &angles, &times,  velocity);
}

void skeleton::NaoMotor::interpolationBezier(const std::vector<float> angles, const std::vector<float> &times) {
    motorInterpolationWithBezier(this->name, &angles, &times);
}

void skeleton::NaoMotor::changeAngles(const std::vector<float> &changes, float velocity) {
    motorChangeAngles(this->name, &changes, velocity);
}

void skeleton::NaoMotor::setAngles(const std::vector<float> &angles, float velocity) {
    motorSetAngles(this->name, &angles, velocity);
}

bool skeleton::NaoMotor::areResourcesAvailable() {
	const std::vector<std::string> vectorofResources;
	vectorofResources.push_back(name);
	hallowlevel::areResourcesAvailable(vectorofResources);
}

void skeleton::NaoMotor::killAllTasks() {
	const std::vector<std::string> vectorOfResources;
	vectorOfResources.push_back(name);
	killTasksUsingResources(vectorOfResources);
}

//with only one value in the parameters

//is always absolute
void skeleton::NaoMotor::interpolation_OneValue(float angle, float time) {
    std::vector<float> newAngle = getVector(angle);
    std::vector<float> newTime = getVector(time);

    motorInterpolation(this->name, &newAngle, &newTime, true);
}

void skeleton::NaoMotor::interpolationWithSpeed_OneValue(float angle, float time, float velocity) {
    std::vector<float> newAngle = getVector(angle);
    std::vector<float> newTime = getVector(time);

    motorInterpolationWithSpeed(this->name, &newAngle, &newTime, velocity);
}

void skeleton::NaoMotor::interpolationBezier_OneValue(float angle, float time) {
    std::vector<float> newAngle = getVector(angle);
    std::vector<float> newTime = getVector(time);

    motorInterpolationBezier(this.name, &newAngle, &newTime);
}

void skeleton::NaoMotor::setAngles_OneValue(float angle, float velocity) {
    std::vector<float> newAngle = getVector(angle);

    motorSetAngles(this->name, &newAngle, velocity);
}

void skeleton::NaoMotor::changeAngles_OneValue(float change, float velocity) {
    std::vector<float> newAngle = getVector(change);

    motorChangeAngles(this->name, &newAngle, velocity);
}

std::vector<float> skeleton::NaoMotor::motorGetAngles(bool useSensors) {
    motorGetAngles(this->name, useSensors);
}

void skeleton::openMotorFile() {
    ifstream motorFile;
    std::string newLine;
    motorFile.open(FILENAME);

    while(!motorFile.eof){
        getLine(motorFile, newLine);
        NaoMotor* tmp = new naoMotor(newLine);
        skeleton::motorCollection.insert(std::pair<std::string,NaoMotor>(newLine, tmp));
    }
    motorFile.close();
}
void skeleton::NaoMotor::getVector(float value) {
    std::vector newVector;
    newVector.push_back(value);
    return newVector;
}