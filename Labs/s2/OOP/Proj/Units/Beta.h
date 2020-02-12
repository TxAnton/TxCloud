//
// Created by anton on 2/12/20.
//

#ifndef PROJ_BETA_H
#define PROJ_BETA_H


#include "God.h"

class Beta: God {
private:
public:
    char toChar();

    bool isValidStep(int x, int y);

    bool step(int x, int y);

};


#endif //PROJ_BETA_H
