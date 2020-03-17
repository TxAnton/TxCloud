//
// Created by anton on 2/11/20.
//

#include "GameObject.h"



//#include "Observer.h"

GameObject::GameObject(Field *fld, int x, int y, int health, UnitDevotion devotion, bool active) {
    //this->fld= fld;//TODO replace with interface
    this->health = health;
    this->devotion = devotion;
    this->active = active;
    this->x = x;
    this->y = y;
}

GameObject::GameObject() {

    //this->fld= nullptr;//TODO replace with interface
    this->health = 0;
    this->devotion = UnitDevotion::NEUTER;
    this->active = false;
    this->x = -1;
    this->y = -1;
}

void GameObject::getCoords(int &x, int &y) {
    x = this->x;
    y = this->y;
}

void GameObject::setCoords(int x, int y) {
    this->x = x;
    this->y = y;
}

bool GameObject::isActive() {
    return this->active;
}

void GameObject::setActive(bool flag) {
    this->active = flag;
}

UnitDevotion GameObject::getUnitDevotion() {
    return UnitDevotion::NEUTER;
}

UnitType GameObject::classToType(UnitClass unitClass) {
    switch (unitClass) {
        case UnitClass::ALPHA:
            return UnitType::GOD;
        case UnitClass::BETA:
            return UnitType::GOD;
        case UnitClass::GAMMA:
            return UnitType::FIGHTER;
        case UnitClass::DELTA:
            return UnitType::MAGE;
        case UnitClass::EPSILON:
            return UnitType::MAGE;
        case UnitClass::ZETA:
            return UnitType::FIGHTER;
        case UnitClass::NO_CLASS:
            return UnitType::NO_TYPE;
    }
}

bool GameObject::die(GameObject *src) {
//    observer->notifyDeath(this);
    return true;
}
