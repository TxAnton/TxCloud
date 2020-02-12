//
// Created by anton on 2/12/20.
//

#ifndef PROJ_GOD_H
#define PROJ_GOD_H

#include "../GameObject.h"



class God:GameObject {
private:


public:
    void deathWill();

    void summon(Direction dir);

    virtual char toChar();

    virtual bool isValidStep(int x, int y);

    virtual bool step(int x, int y);
};


#endif //PROJ_GOD_H
