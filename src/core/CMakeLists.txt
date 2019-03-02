cmake_minimum_required(VERSION 3.5)
project(Core)

#set sources of your project here
set(HEADERS
        Brain.h
        EngineBase.h
        Intent.h
        Logger.h
        Memory.h
        StandardIntents.h
)

set(SOURCES
        Brain.cpp
        EngineBase.cpp
        Logger.cpp
        Memory.cpp
)

add_library(Duckburg OBJECT ${SOURCES} ${HEADERS})


target_include_directories(Duckburg SYSTEM PUBLIC ${TUHH_DEPS_INCLUDE_DIRECTORIES})
target_link_libraries(Duckburg ${TUHH_DEPS_LIBRARIES})


#add_library(${PROJECT_NAME} OBJECT ${SOURCES} ${HEADERS})
#target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#assign_source_group(${SOURCES} ${HEADERS})
