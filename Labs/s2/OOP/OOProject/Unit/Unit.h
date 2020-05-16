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
    Unit(int x, int y, Devotion devotion, CommonClass objectClass, int health, int armour, float dmgmul,
         int abPower, int abRange, int mbAgility, int mbRange, UnitType unitClass);

    void act(std::shared_ptr<GameObject> obj) override;

    void react(std::shared_ptr<GameObject> sbj) override;

    void step(std::shared_ptr<GameObject> obj) override;

    void restep(std::shared_ptr<GameObject> sbj) override;

    bool canStep(int x, int y) override;

    bool canAct(int x, int y) override;

    CommonClass getObjectClass() override;

private:
    Ability ability;
    Mobility mobility;
    UnitType unitClass;


    
};


#endif //OOPROJECT_UNIT_H
