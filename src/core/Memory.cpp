//
// Created by obyoxar on 20/11/18.
//

#include <iostream>
#include "Logger.h"
#include "Memory.h"

#define LOG_TAG LOGGER(Memory)

std::string Memory::getType(const std::string& key) const {
    return getTypeNameFromId(this->_vals.at(key).which());
}

std::string Memory::getTypeNameFromId(int id) const {
    return _types[id];
}

void *Memory::readRegister(int index) {
    //TODO Index-Range check
    return _registers[index];
}

void Memory::writeRegister(int index, void *data) {
    _registers[index] = data;
}

void Memory::debugMemory() {
    for (const auto &_val : _vals) {
        LFINFO(_val.first << ": " << _val.second)
    }
}


IMPLEMENT_SINGLETON(Memory)