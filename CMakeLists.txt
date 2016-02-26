cmake_minimum_required(VERSION 3.3)
project(3)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/Users/connor/sp2016/cs5201/Homework/3/")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES driver.cpp vector.h vector.hpp norm.h norm.hpp qrdecomp.h qrdecomp.hpp)
add_executable(3 ${SOURCE_FILES})