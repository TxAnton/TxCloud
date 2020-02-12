//
// Created by anton on 2/12/20.
//

#ifndef PROJ_DELTA_H
#define PROJ_DELTA_H


#include "Mage.h"

class Delta: Mage {
private:
    int girdle;
public:
    char toChar();

    bool isValidStep(int x, int y);

    bool step(int x, int y);
};


#endif //PROJ_DELTA_H
