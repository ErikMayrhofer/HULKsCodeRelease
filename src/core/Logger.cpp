//
// Created by obyoxar on 27/11/18.
//

#include "Logger.h"

IMPLEMENT_SINGLETON(Logger)

DISPATCHER_IMPL(Stdout)(unsigned char level, const char* /*prefix*/, const char */*message*/, std::string& formattedStr, std::tm* /*time*/) {
    auto stream = &std::cout;
    if(level <= MAX_LEVEL_CERR){
        stream = &std::cerr;
    }
    (*stream) << formattedStr;
    (*stream).flush();
}

const std::string Logger::getLevelString(int level) {
    return _levels[level];
}
