//
// Created by anton on 3/2/20.
//

#ifndef PROJ_GAMEOBJECTSET_H
#define PROJ_GAMEOBJECTSET_H


#include <list>

#include "GameObject.h"


class GameObjectSet {
private:
    std::list<GameObject> container;
public:
    GameObjectSet()=default;
    GameObjectSet(GameObjectSet& src);
    GameObjectSet(std::list<GameObject*> lst);

    GameObjectSet& ofDevotion(UnitDevotion unitDevotion, bool inclusive = true);
    GameObjectSet& ofClass(UnitClass unitClass, bool inclusive  = true);
    GameObjectSet& ofType(UnitType unitType, bool inclusive  = true);


};


#endif //PROJ_GAMEOBJECTSET_H
