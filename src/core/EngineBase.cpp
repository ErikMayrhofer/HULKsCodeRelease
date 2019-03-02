//return 0;
// Created by obyoxar on 09/10/18.
//

#include "EngineBase.h"

void EngineBase::setProperties(boost::property_tree::ptree props) {
    this->config = new boost::property_tree::ptree(props);
}

EngineBase::~EngineBase() {
    delete this->config;
}
