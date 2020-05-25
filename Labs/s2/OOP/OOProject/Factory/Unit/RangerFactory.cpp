//
// Created by anton on 5/25/20.
//

#include "RangerFactory.h"

#include "../../Unit/TheRanger.h"

std::shared_ptr<GameObject> RangerFactory::createObject(int x, int y, Devotion devotion) {
    auto rPtr = std::make_shared<TheRanger>(x,y,devotion,health,armour,dmgmul,abPower,enhancedRange,mbAgility,mbRange);
    return std::static_pointer_cast<GameObject>(rPtr);
}

RangerFactory::RangerFactory(int health, int armour, float dmgmul, int abPower, int abRange, int mbAgility, int mbRange,
                             int enhancedRange) : AbstractUnitFactory(health, armour, dmgmul, abPower, abRange,
                                                                      mbAgility, mbRange),
                                                  enhancedRange(enhancedRange) {}
