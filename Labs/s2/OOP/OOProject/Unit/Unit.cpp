//
// Created by anton on 5/9/20.
//

#include "Unit.h"

Unit::Unit(int x, int y, Devotion devotion, ObjectType objectType, CommonClass objectClass, int health, int armour,
           float dmgmul, int abPower, int abRange, int mbAgility, int mbRange, UnitType unitClass)
        : GameObject(x, y, false, devotion, objectType, objectClass, health, armour, dmgmul), ability(abPower,abRange,this),
          mobility(mbAgility,mbRange,this), unitClass(unitClass) {}
