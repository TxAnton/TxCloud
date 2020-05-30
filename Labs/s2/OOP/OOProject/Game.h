//
// Created by anton on 5/9/20.
//

#ifndef OOPROJECT_GAME_H
#define OOPROJECT_GAME_H

#include <iostream>
#include "Field.h"
#include "Factory/CommonFactory.h"
#include "Mediator.h"

class Game {

private:
    static Game* instance;

    Field* field;

    CommonFactory* factory;

    Mediator* mediator;

    int width;
    int height;

public:


    Game(int width, int height);

    void initField();

    static Game &getInstance();


    void demo();
};


#endif //OOPROJECT_GAME_H
