//
// Created by anton on 2/12/20.
//

#include "Fighter.h"

bool Fighter::isAllyPowered() const {
    return allyPowered;
}

void Fighter::setAllyPowered(bool allyPowered) {
    Fighter::allyPowered = allyPowered;
}

bool Fighter::isEnemyPowered() const {
    return enemyPowered;
}

void Fighter::setEnemyPowered(bool enemyPowered) {
    Fighter::enemyPowered = enemyPowered;
}
