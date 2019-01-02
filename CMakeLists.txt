cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-O0 -Wall -g -std=c++11 -ggdb")
set(CMAKE_C_FLAGS "-O0 -Wall -g -std=c11 -ggdb")

add_executable(test1 main.cc simplog.h simplog.c)

SET(LIBS pthread wiringPi)

target_link_libraries(test1 ${LIBS} )

add_executable(test2 test2.cc simplog.h simplog.c)

target_link_libraries(test2 ${LIBS} )

