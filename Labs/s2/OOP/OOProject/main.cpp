#include <iostream>

#include "Game.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Game game = Game::getInstance();

    game.demo();
    return 0;
}