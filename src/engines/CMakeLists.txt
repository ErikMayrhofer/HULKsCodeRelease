cmake_minimum_required(VERSION 3.5)
project(Engines CXX)

add_custom_target(AllEngines)
macro(add_engine)
    cmake_parse_arguments(ARGS "" "" "" ${ARGN})
    list(GET ARGS_UNPARSED_ARGUMENTS 0 ARGS_NAME)
    list(REMOVE_AT ARGS_UNPARSED_ARGUMENTS 0)
    set(ARGS_SRCS "${ARGS_UNPARSED_ARGUMENTS}")
    message(STATUS "Adding '${ARGS_NAME}' with: ")
    message(STATUS " Sources: ${ARGS_SRCS}")

    add_library(${ARGS_NAME} SHARED ${ARGS_SRCS})
    add_dependencies(AllEngines ${ARGS_NAME})

    target_include_directories(${ARGS_NAME} SYSTEM PUBLIC ${TUHH_DEPS_INCLUDE_DIRECTORIES})
    target_link_libraries(${ARGS_NAME} ${TUHH_DEPS_LIBRARIES})
endmacro()


add_engine(ExampleEngine ExampleEngine.cpp ExampleEngine.h)
target_link_libraries(ExampleEngine Duckburg)

add_engine(RemoteEngine RemoteEngine.h RemoteEngine.cpp)
target_link_libraries(RemoteEngine Duckburg Boost::boost)

add_engine(LoggingEngine LoggingEngine.h LoggingEngine.cpp)
target_link_libraries(LoggingEngine Duckburg Boost::boost)
