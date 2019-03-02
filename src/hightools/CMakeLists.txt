cmake_minimum_required(VERSION 3.5)
project(hightools)

#set sources of your project here
set(HEADERS
        BetterClass.h
        Dyllo.h
        StringUtil.h
        TimeUtil.h
        )

set(SOURCES
        )


add_library(${PROJECT_NAME} OBJECT ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

assign_source_group(${SOURCES} ${HEADERS})
