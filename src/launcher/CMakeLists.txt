cmake_minimum_required(VERSION 3.12)
project(launcher CXX)

add_executable(launcher Duckinga.cpp)
target_link_libraries(launcher Duckburg)

configure_file(conf.xml conf.xml)

target_include_directories(launcher SYSTEM PUBLIC ${TUHH_DEPS_INCLUDE_DIRECTORIES})
target_link_libraries(launcher ${TUHH_DEPS_LIBRARIES})