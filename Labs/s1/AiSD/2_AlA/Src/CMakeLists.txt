cmake_minimum_required(VERSION 3.14)
project(Src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Src
        l_impl_.cpp
        l_intrfc_.h
        l_mod1_.cpp
        l_mod1_.h)
