//
// Created by obyoxar on 08/10/18.
//

#ifndef DUCKBURG_DLSIMPLE_H
#define DUCKBURG_DLSIMPLE_H

#include <string>
#include <dlfcn.h>
#include <iostream>
#include <sstream>
#include <boost/dll/import.hpp>

/*
#define DL_CLASS_PUBLISH(Classname) \
extern "C" Classname* __dl_create_##Classname(){return new Classname;}
*/

#define DL_CLASS_PUBLISH(Classname) \
extern "C" BOOST_SYMBOL_EXPORT Classname Classname; \
class Classname Classname;

template<typename T>
T* dl_load_class(const std::string &filename, const std::string& classname){
    /*
    std::stringstream filepath;
    filepath << "./" << filename;

    void* handle = dlopen(filepath.str().c_str(), RTLD_LAZY);
    if(handle == nullptr){
        std::stringstream stream;
        stream << "Could not open " << filename << " for dynamic loading: " << dlerror();
        throw std::runtime_error(stream.str());
    }

    std::string create_fun = "__dl_create_";
    create_fun = create_fun.append(classname);

    T* (*create)();
    create = (T* (*)())dlsym(handle, create_fun.c_str());

    if(create == nullptr){
        std::stringstream stream;
        stream << "Could not load function: " << create_fun << " from " << filename << ". Probably DL_CLASS_PUBLISH was forgotten";
        throw std::runtime_error(stream.str());
    }

    auto * myClass = create();
    return myClass;*/

    boost::filesystem::path lib_path(filename);
    auto myEngine = boost::dll::import<T>(
            lib_path,
            classname,
            boost::dll::load_mode::append_decorations
            ).get();
    return myEngine;
}

#endif //DUCKBURG_DLSIMPLE_H
