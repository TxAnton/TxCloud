//
// Created by anton on 2/12/20.
//

#ifndef PROJ_MAGE_H
#define PROJ_MAGE_H


#include "../GameObject.h"

class Mage: GameObject {
private:

public:
    virtual int getPower();
    virtual bool ability();
};


#endif //PROJ_MAGE_H
