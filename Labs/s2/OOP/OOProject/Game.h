//
// Created by anton on 5/9/20.
//

#ifndef OOPROJECT_GAME_H
#define OOPROJECT_GAME_H

#include <iostream>
#include "Field.h"

class Game {

private:
    static Game* instance;

    Field* field;
public:
    static Game &getInstance();


    void demo();
};


#endif //OOPROJECT_GAME_H
