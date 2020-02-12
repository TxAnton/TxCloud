//
// Created by anton on 2/12/20.
//

#include "Zeta.h"

bool Zeta::isAllyPowered() const {
    return allyPowered;
}

void Zeta::setAllyPowered(bool allyPowered) {
    Zeta::allyPowered = allyPowered;
}

bool Zeta::isEnemyPowered() const {
    return enemyPowered;
}

void Zeta::setEnemyPowered(bool enemyPowered) {
    Zeta::enemyPowered = enemyPowered;
}
