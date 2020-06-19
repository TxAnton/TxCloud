//
// Created by anton on 6/2/20.
//

#include "AI.h"

AI::AI(const std::string &name) : Actor(name) {}

void AI::notify(std::string string) {

}

void AI::turn() {
    if(!b){summon(2,4,UnitClass::TheVampire);
    b= true;}
}
