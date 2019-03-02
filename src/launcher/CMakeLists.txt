cmake_minimum_required(VERSION 3.12)
project(Launcher CXX)

add_executable(Launcher Duckinga.cpp)
target_link_libraries(Launcher Duckburg)

configure_file(conf.xml conf.xml)

target_include_directories(Launcher SYSTEM PUBLIC ${TUHH_DEPS_INCLUDE_DIRECTORIES})
target_link_libraries(Launcher ${TUHH_DEPS_LIBRARIES})