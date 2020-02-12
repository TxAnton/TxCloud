//
// Created by anton on 2/11/20.
//

#ifndef PROJ_GAME_H
#define PROJ_GAME_H

#include <assert.h>
#include <iostream>

#include "Field.h"

class Game {
private:
    Field *fld;

public:
    Game(int fieldWidth, int fieldHeight);

    void run();
};


#endif //PROJ_GAME_H
