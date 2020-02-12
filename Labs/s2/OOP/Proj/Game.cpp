//
// Created by anton on 2/11/20.
//

#include "Game.h"



Game::Game(int fieldWidth, int fieldHeight) {
    fld = new Field(fieldWidth, fieldHeight, fieldHeight * fieldWidth);
}

void Game::run() {
    std::cout<<fld->toString();
}
