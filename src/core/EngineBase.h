//
// Created by obyoxar on 09/10/18.
//

#ifndef DUCKBURG_ENGINEBASE_H
#define DUCKBURG_ENGINEBASE_H


#include <boost/property_tree/ptree.hpp>

//Increment this everytime anything crucial changes around EngineBase to make sure, that
//Engines compiled against older versions don't make troubles.
#define ENGINE_BASE_VERSION 4

class EngineBase {
public:
    virtual ~EngineBase();
    virtual const char* getName() = 0;
    virtual void onLoad() = 0;

    virtual unsigned int getEngineBaseVersion() = 0;

    void setProperties(boost::property_tree::ptree props);

protected:
    boost::property_tree::ptree* config = nullptr;
};

#endif