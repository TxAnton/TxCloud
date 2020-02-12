cmake_minimum_required(VERSION 3.14)
project(Proj)

set(CMAKE_CXX_STANDARD 14)

add_executable(Proj main.cpp Game.cpp Game.h Field.cpp Field.h GameObject.cpp GameObject.h Units/Zeta.cpp Units/Zeta.h Units/Mage.cpp Units/Mage.h Units/God.cpp Units/God.h Units/Alpha.cpp Units/Alpha.h Units/Beta.cpp Units/Beta.h Units/Gamma.cpp Units/Gamma.h Units/Delta.cpp Units/Delta.h Units/Epsilon.cpp Units/Epsilon.h)