cmake_minimum_required(VERSION 3.24)
project(vaja02)

set(CMAKE_CXX_STANDARD 17)

add_executable(vaja02 main.cpp main.h)
add_executable(vaja02_test test_main.cpp main.h)
