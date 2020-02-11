cmake_minimum_required(VERSION 3.14)
project(Code C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Code
        AVLTree.h AVLTreeClass.h main.cpp)
