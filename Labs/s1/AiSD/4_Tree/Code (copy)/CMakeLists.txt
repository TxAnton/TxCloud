cmake_minimum_required(VERSION 3.14)
project(Code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Code
        bt_implementation.cpp
        Btree.h
        work_bt.cpp Btree_.h)
