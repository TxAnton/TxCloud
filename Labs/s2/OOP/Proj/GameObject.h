//
// Created by anton on 2/11/20.
//

#ifndef PROJ_GAMEOBJECT_H
#define PROJ_GAMEOBJECT_H


//#include "Game.h"

class Field;

enum Direction{
    UP,
    RIGHT,
    DOWN,
    LEFT
};

enum UnitClass{
    ALPHA,
    BETA,
    GAMMA,
    DELTA,
    EPSILON,
    ZETA,
    NO_CLASS
};,

class GameObject {
private:
    Field *fld;
    int health;
    bool side;
    bool active;
    int x;
    int y;
public:
    GameObject(int x, int y);

    GameObject();

    void getCoords(int &x, int &y);

    void setCoords(int x, int y);

    bool isActive();

    void setActive(bool flag);

    virtual char toChar();

    virtual bool isValidStep(int x, int y);

    virtual bool step(int x, int y);

    virtual UnitClass getUnitClass();
};


#endif //PROJ_GAMEOBJECT_H
