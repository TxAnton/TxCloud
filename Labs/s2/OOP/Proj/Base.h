//
// Created by anton on 2/25/20.
//

#ifndef PROJ_BASE_H
#define PROJ_BASE_H

#include "GameObject.h"

class Base {

private:

public:
    virtual int getUnitLim() = 0;

    virtual void setUnitLim(int unitLim) = 0;

    virtual bool spawnAt(UnitClass unitClass, int x, int y) = 0;
};

#endif //PROJ_BASE_H
