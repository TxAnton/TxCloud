//
// Created by anton on 5/9/20.
//

#include "Unit.h"



Unit::Unit(int x, int y, Devotion devotion, CommonClass objectClass, int health, int armour, float dmgmul,
           int abPower, int abRange, int mbAgility, int mbRange, UnitType unitClass)
        : GameObject(x, y, false, devotion, ObjectType::Unit, objectClass, health, armour, dmgmul), ability(abPower,abRange,this),
          mobility(mbAgility,mbRange,this), unitClass(unitClass) {}

void Unit::act(std::shared_ptr<GameObject> obj) {
    std::shared_ptr<Unit> unit = std::dynamic_pointer_cast<Unit>(obj);
    if(unit){
        unit->getVitality().damage(this->ability.power);
    }
}

void Unit::react(std::shared_ptr<GameObject> sbj) {

}

void Unit::step(std::shared_ptr<GameObject> obj) {
    setCoords(obj->getCoords());
}

void Unit::restep(std::shared_ptr<GameObject> sbj) {

}

bool Unit::canStep(int x, int y) {
    return true;//TODO
}

bool Unit::canAct(int x, int y) {
    return true;//TODO
}

CommonClass Unit::getObjectClass() {
    return CommonClass::NONE;
}
