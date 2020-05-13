//
// Created by anton on 5/9/20.
//

#ifndef OOPROJECT_ABILITY_H
#define OOPROJECT_ABILITY_H


//#include "GameObject.h"
class GameObject;

class Ability {
    int power;
    int range;
    GameObject* master;

public:
    Ability(int power, int range, GameObject *master);

private:
    bool canAct(int x, int y);
};


#endif //OOPROJECT_ABILITY_H
