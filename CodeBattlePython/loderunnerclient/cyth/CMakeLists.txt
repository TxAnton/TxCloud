cmake_minimum_required(VERSION 3.14)
project(cyth)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cyth
        BMPTools.h
        cyth.cpp)
