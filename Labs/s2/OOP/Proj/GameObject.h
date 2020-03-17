//
// Created by anton on 2/11/20.
//

#ifndef PROJ_GAMEOBJECT_H
#define PROJ_GAMEOBJECT_H

#include <cwchar>

//#include "Observee.h"

#include "Mediator.h"

class Field;

//class Observer;

//class Mediator;

//class LandscapeProxy;
//class FieldCellProxy;

#include "LandscapeProxy.h"//TODO can do some troubs here
#include "FieldCellProxy.h"

enum class Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

enum class UnitClass {
    ALPHA,
    BETA,
    GAMMA,
    DELTA,
    EPSILON,
    ZETA,
    NO_CLASS
};


enum class UnitType {
    GOD,
    MAGE,
    FIGHTER,
    NO_TYPE
};

enum class UnitDevotion {
    LIGHT,
    DARK,
    NEUTER
};

//#include "LandscapeProxy.h"


class GameObject {

public:
    static Mediator *mediator;
    static Observer *observer;
private:
    //Field *fld;//TODO replace with interface
    int health;
    UnitDevotion devotion;
    bool active;
    int x;
    int y;
public:
    GameObject(Field *fld, int x, int y, int health = 0, UnitDevotion devotion = UnitDevotion::NEUTER,
               bool active = false);

    GameObject();

    void getCoords(int &x, int &y);

    void setCoords(int x, int y);

    bool isActive();

    void setActive(bool flag);

    virtual wchar_t toChar() = 0;

    virtual bool isValidStep(int x, int y) = 0;

    virtual bool step(int x, int y) = 0;

    virtual bool die(GameObject *src);

    virtual UnitClass getUnitClass() = 0;

    virtual UnitDevotion getUnitDevotion();

    virtual GameObject &operator+=(const LandscapeProxy &b) = 0;

    virtual GameObject &operator+=(const FieldCellProxy &b) = 0;

    virtual GameObject &operator-=(const GameObject &b) = 0;



    static UnitType classToType(UnitClass unitClass);
};


#endif //PROJ_GAMEOBJECT_H
