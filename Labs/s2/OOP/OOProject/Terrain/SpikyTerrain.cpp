//
// Created by anton on 5/16/20.
//

#include "SpikyTerrain.h"

SpikyTerrain::SpikyTerrain(int x, int y, int damage) : Terrain(x,
                                                               y,
                                                               CommonClass::Terrain1,
                                                               TerrainType::SpikyTerrain,
                                                               defaultSteepness) {this->damage=damage;}

void SpikyTerrain::restep(std::shared_ptr<GameObject> sbj) {
    sbj->getVitality().damage(damage);
}
