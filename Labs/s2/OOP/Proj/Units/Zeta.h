//
// Created by anton on 2/12/20.
//

#ifndef PROJ_ZETA_H
#define PROJ_ZETA_H


#include "../GameObject.h"

class Zeta : GameObject {
private:
    bool allyPowered;
    bool enemyPowered;
public:
    bool isAllyPowered() const;

    void setAllyPowered(bool allyPowered);

    bool isEnemyPowered() const;

    void setEnemyPowered(bool enemyPowered);

    bool isValidStep(int x, int y);

    char toChar();
};


#endif //PROJ_ZETA_H
