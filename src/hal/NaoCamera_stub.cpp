//
// Created by max on 11/22/18.
//

#include "NaoCamera.h"
#include <iostream>


void NaoCamera::init() {
    std::cout << "NaoCamera::init stub"<<std::endl;
}

void NaoCamera::start() {
    std::cout << "NaoCamera::start stub"<<std::endl;
}
Image* NaoCamera::takePicture() {
    std::cout << "NaoCamera::takePicture stub"<<std::endl;
    return nullptr;
}

NaoCamera::~NaoCamera(){
    std::cout << "NaoCamera::destructor stub"<<std::endl;

}