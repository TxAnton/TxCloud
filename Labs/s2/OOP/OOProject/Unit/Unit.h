//
// Created by anton on 5/9/20.
//

#ifndef OOPROJECT_UNIT_H
#define OOPROJECT_UNIT_H


#include "../GameObject.h"
#include "../Ability.h"
#include "../Mobility.h"

class Unit: public GameObject {
public:
    Unit(int x, int y, Devotion devotion, ObjectType objectType, CommonClass objectClass, int health, int armour,
         float dmgmul, int abPower, int abRange, int mbAgility, int mbRange, UnitType unitClass);

private:
    Ability ability;
    Mobility mobility;
    UnitType unitClass;


};


#endif //OOPROJECT_UNIT_H
