//
// Created by anton on 5/25/20.
//

#include "AbstractUnitFactory.h"

AbstractUnitFactory::AbstractUnitFactory(int health, int armour, float dmgmul, int abPower, int abRange, int mbAgility,
                                         int mbRange) : health(health), armour(armour), dmgmul(dmgmul),
                                                        abPower(abPower), abRange(abRange), mbAgility(mbAgility),
                                                        mbRange(mbRange) {}
