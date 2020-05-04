#include <iostream>
#include "stdio.h"

#include <clocale>


#include <iostream>
#include"Game.h"
#include "Vector.h"


int main() {

    int a;

    std::vector<int> v;

    printf("%f",0.5);
    std::cout<<5<<0.5;

    return 0;



    std::setlocale(LC_ALL, "xx_XX.UTF-8");
    std::cout << "Hello, World!" << std::endl;
    Game* game = new Game(8,8);
    game->run();

    Vector<int> vec;
    vec.push(5);
    vec.push(6);
    vec.push(7);
    vec.pop();
    std::cout << vec.toString() << std::endl;

    return 0;
}