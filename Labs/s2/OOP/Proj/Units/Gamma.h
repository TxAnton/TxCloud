//
// Created by anton on 2/12/20.
//

#ifndef PROJ_GAMMA_H
#define PROJ_GAMMA_H


#include <utility>
#include "Mage.h"

class Gamma : Mage {
private:
    std::pair<int, int> link;
public:
    std::pair<int, int> *getIntersects(int &amount);

    char toChar();

    bool isValidStep(int x, int y);

    bool step(int x, int y);
};


#endif //PROJ_GAMMA_H
