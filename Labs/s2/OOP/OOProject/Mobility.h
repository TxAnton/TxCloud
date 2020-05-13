//
// Created by anton on 5/9/20.
//

#ifndef OOPROJECT_MOBILITY_H
#define OOPROJECT_MOBILITY_H


//#include "GameObject.h"
class GameObject;

class Mobility {
public:
    Mobility(int agility, int range, GameObject *master);

private:
    int agility;
    int range;
    GameObject* master;


};


#endif //OOPROJECT_MOBILITY_H
