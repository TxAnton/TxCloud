//
// Created by anton on 5/26/20.
//

#include "ToughFactory.h"

#include "../../Unit/TheTough.h"


ToughFactory::ToughFactory(int health, int armour, float dmgmul, int abPower, int abRange, int mbAgility, int mbRange,
                           int enhancedHealth) : AbstractUnitFactory(health, armour, dmgmul, abPower, abRange,
                                                                     mbAgility, mbRange),
                                                 enhancedHealth(enhancedHealth) {}

std::shared_ptr<GameObject> ToughFactory::createObject(int x, int y, Devotion devotion) {
    auto rPtr = std::make_shared<TheTough>(x,y,devotion,enhancedHealth,armour,dmgmul,abPower,abRange,mbAgility,mbRange);
    return std::static_pointer_cast<GameObject>(rPtr);
}
