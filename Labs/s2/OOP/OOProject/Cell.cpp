//
// Created by anton on 5/10/20.
//

#include "Cell.h"

Cell::Cell(std::shared_ptr<Unit> &unit) : unit(unit) {}

std::shared_ptr<Unit> &Cell::getUnit() {
    return unit;
}

void Cell::setUnit(std::shared_ptr<Unit> &unit) {
    Cell::unit = unit;
}

std::shared_ptr<Terrain> &Cell::getTerrain() {
    return terrain;
}

void Cell::setTerrain(std::shared_ptr<Terrain> &terrain) {
    Cell::terrain = terrain;
}

std::shared_ptr<Entity> &Cell::getEntity() {
    return entity;
}

void Cell::setEntity(std::shared_ptr<Entity> &entity) {
    Cell::entity = entity;
}
