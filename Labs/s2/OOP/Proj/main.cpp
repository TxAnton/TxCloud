#include <iostream>

#include"Game.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Game* game = new Game(8,8);
    game->run();
    return 0;
}