cmake_minimum_required(VERSION 3.14)
project(OOProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOProject main.cpp Game.cpp Game.h GameObject.cpp GameObject.h Stats.h Vitality.cpp Vitality.h Unit/Unit.cpp Unit/Unit.h Ability.cpp Ability.h Mobility.cpp Mobility.h Field.cpp Field.h Cell.cpp Cell.h Terrain/Terrain.cpp Terrain/Terrain.h Entity/Entity.cpp Entity/Entity.h)