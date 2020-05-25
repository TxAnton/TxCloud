//
// Created by anton on 5/25/20.
//

#ifndef OOPROJECT_ABSTRACTUNITFACTORY_H
#define OOPROJECT_ABSTRACTUNITFACTORY_H

#include "../AbstractFactory.h"

class AbstractUnitFactory:public AbstractFactory{
public:
    AbstractUnitFactory(int health, int armour, float dmgmul, int abPower, int abRange, int mbAgility, int mbRange);

protected:
    int health = 100;
    int armour = 100;
    float dmgmul = 1;
    int abPower=10;
    int abRange=2;
    int mbAgility=5;
    int mbRange=5;

};


#endif //OOPROJECT_ABSTRACTUNITFACTORY_H
