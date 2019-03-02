//
// Created by obyoxar on 27/11/18.
//

#ifndef DUCKBURG_LOGGER_H
#define DUCKBURG_LOGGER_H
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/cat.hpp>
#include <string>
#include <iostream>
#include <iomanip>

#include "../hightools/BetterClass.h"

#define LEVEL_EMERGENCY 0
#define LEVEL_ALERT 1
#define LEVEL_CRIT 2
#define LEVEL_ERR 3
#define LEVEL_WARN 4
#define LEVEL_NOTICE 5
#define LEVEL_INFO 6
#define LEVEL_DEBUG 7
#ifndef MAX_LEVEL_CERR
#define MAX_LEVEL_CERR LEVEL_WARN //Messages more critical than this log-level will get logged to std::Cerr
#endif

#ifndef LOG_LEVEL
#define LOG_LEVEL LEVEL_INFO
#endif
#if LOG_LEVEL <= LEVEL_CRIT
#warning The specified LOG_LEVEL is less verbose than LEVEL_WARN. This is discouraged \
since crucial error-messages will be dropped.
#endif

#define DISPATCHER(r, data, name) void BOOST_PP_CAT(dispatch, name)(unsigned char level, const char* prefix, const char* message, std::string& formattedStr, std::tm* time);
#define DISPATCHERCALL(r, data, name) this->BOOST_PP_CAT(dispatch, name)(level, prefix, message, formattedStr, localtime);
#define LOGGER_IMPL(list) \
    void log(unsigned char level, const char* prefix, const char* message) { \
        auto t = std::time(nullptr); \
        std::stringstream stream;\
        std::tm* localtime = std::localtime(&t);\
        stream << std::put_time(localtime, "[%d.%m.%Y-%H/%M/%S]") << "[" << getLevelString(level) << "][" << prefix << "]: "  << message << std::endl;\
        std::string formattedStr = stream.str();\
    \
    BOOST_PP_SEQ_FOR_EACH(DISPATCHERCALL, _, list) } private: BOOST_PP_SEQ_FOR_EACH(DISPATCHER, _, list)

#define DISPATCHER_IMPL(name) void Logger::BOOST_PP_CAT(dispatch, name)

#define LOG(level,  message) Logger::getInstance()->log(level, LOG_TAG, message);
#define LOGF(level,  message) {\
    std::stringstream ss; \
    ss << message; \
    LOG(level, ss.str().c_str())\
}\

#define LOGGER(name) BOOST_PP_STRINGIZE(name)


#if LOG_LEVEL >= LEVEL_DEBUG
#define LDEBUG(message) LOG(LEVEL_DEBUG, message)
#define LFDEBUG(message) LOGF(LEVEL_DEBUG, message)
#define DEBUG_MODE
#else
#define LDEBUG(message)
#define LFDEBUG(message)
#endif

#if LOG_LEVEL >= LEVEL_INFO
#define LINFO(message) LOG(LEVEL_INFO, message)
#define LFINFO(message) LOGF(LEVEL_INFO, message)
#else
#define LINFO(message)
#define LFINFO(message)
#endif

#if LOG_LEVEL >= LEVEL_NOTICE
#define LNOTICE(message) LOG(LEVEL_NOTICE, message)
#define LFNOTICE(message) LOGF(LEVEL_NOTICE, message)
#else
#define LNOTICE(message)
#define LFNOTICE(message)
#endif

#if LOG_LEVEL >= LEVEL_WARN
#define LWARN(message) LOG(LEVEL_WARN, message)
#define LFWARN(message) LOGF(LEVEL_WARN, message)
#else
#define LWARN(message)
#define LFWARN(message)
#endif

#if LOG_LEVEL >= LEVEL_ERR
#define LERR(message) LOG(LEVEL_ERR, message)
#define LFERR(message) LOGF(LEVEL_ERR, message)
#else
#define LERR(message)
#define LFERR(message)
#endif

#if LOG_LEVEL >= LEVEL_CRIT
#define LCRIT(message) LOG(LEVEL_CRIT, message)
#define LFCRIT(message) LOGF(LEVEL_CRIT, message)
#else
#define LCRIT(message)
#define LFCRIT(message)
#endif

#if LOG_LEVEL >= LEVEL_ALERT
#define LALERT(message) LOG(LEVEL_ALERT, message)
#define LFALERT(message) LOGF(LEVEL_ALERT, message)
#else
#define LALERT(message)
#define LFALERT(message)
#endif

#if LOG_LEVEL >= LEVEL_EMERGENCY
#define LEMERGENCY(message) LOG(LEVEL_EMERGENCY, message)
#define LFEMERGENCY(message) LOGF(LEVEL_EMERGENCY, message)
#else
#define LEMERGENCY(message)
#define LFEMERGENCY(message)
#endif

#define DISPATCHERS (Stdout)


class Logger {
    SINGLETON(Logger)
public:
    LOGGER_IMPL(DISPATCHERS)

    const std::string getLevelString(int level);

private:
    const std::string _levels[8] = {
        "Emergency",
        "Alert",
        "Critical",
        "Error",
        "Warning",
        "Notice",
        "Info",
        "Debug"
    };
};

#undef LOGGER_IMPL
#undef DISPATCHER
#undef DISPATCHERCALL
#undef DISPATCHERS

#endif //DUCKBURG_LOGGER_H
