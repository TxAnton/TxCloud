//
// Created by anton on 2/12/20.
//

#ifndef PROJ_ALPHA_H
#define PROJ_ALPHA_H


#include "God.h"

class Alpha: God {
private:
public:
    char toChar();

    bool isValidStep(int x, int y);

    bool step(int x, int y);

};


#endif //PROJ_ALPHA_H
