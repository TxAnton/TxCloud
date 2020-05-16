//
// Created by anton on 5/16/20.
//

#include "SteepTerrain.h"

SteepTerrain::SteepTerrain(int x, int y) : Terrain(x,
                                                   y,
                                                   CommonClass::Terrain2,
                                                   TerrainType::SteepTerrain,
                                                   highSteepness) {}
