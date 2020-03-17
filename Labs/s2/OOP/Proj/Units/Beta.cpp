//
// Created by anton on 2/12/20.
//

#include "Beta.h"

//#include "../Observer.h"
#include "../Mediator.h"

#include "../LandscapeProxy.h"


UnitClass Beta::getUnitClass() {
    return UnitClass::BETA;
}

void Beta::deathEvent() {
    return;
}

void Beta::summon(Direction dir) {
    God::summon(dir);//TODO
}

wchar_t Beta::toChar() {
    //return L'β';
    return L'b';
}

bool Beta::isValidStep(int x, int y) {
    return true;
}

bool Beta::step(int x, int y) {
    if (isValidStep(x, y)) {
        GameObject::setCoords(x, y);
        return true;
    }
    return false;
}

Beta::Beta(Field *fld, int x, int y, int health, UnitDevotion devotion, bool active) : God(fld, x, y, health, devotion,
                                                                                           active) {}

GameObject &Beta::operator+=(const LandscapeProxy &b) {
    return *this;
}

bool Beta::die(GameObject *src) {
    //mediator->changeGodPowers(getUnitDevotion(),getUnitDevotion()==UnitDevotion::LIGHT?UnitDevotion::DARK:UnitDevotion::LIGHT,false);
//    observer->notifyDeath(this);
    return true;
}

//void Beta::recieveDeath(GameObject *gameObject) {}

//Beta::Beta(Field *fld, int x, int y, int health, UnitDevotion devotion, bool active, CommonFactory *factory, int unitLim) : God(fld, x, y, health, devotion, active), Base(fld, factory, unitLim) {}
