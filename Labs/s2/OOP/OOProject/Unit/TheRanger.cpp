//
// Created by anton on 5/23/20.
//

#include "TheRanger.h"

CommonClass TheRanger::getObjectClass() {
    return CommonClass::Unit1;
}

TheRanger::TheRanger(int x, int y, Devotion devotion, int health, int armour, float dmgmul, int abPower,
                     int abRange, int mbAgility, int mbRange) : AbleUnit(x, y, devotion, CommonClass::Unit1,
                                                                                      health, armour, dmgmul, abPower,
                                                                                      abRange, mbAgility, mbRange) {}


