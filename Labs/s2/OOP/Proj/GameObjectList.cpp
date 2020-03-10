//
// Created by anton on 3/2/20.
//

#include "GameObjectList.h"

GameObjectList::GameObjectList(GameObjectList &src) {
    container=std::list<GameObject>(src.container.begin(),src.container.end());

}

GameObjectList::GameObjectList(std::list<GameObject *> lst) {
    container.insert(container.begin(),lst.begin(),lst.end());
}

GameObjectList &GameObjectList::ofDevotion(UnitDevotion unitDevotion, bool inclusive) {
    for(auto it = container.begin();it!=container.end();it++){
        if(((*it).getUnitDevotion()==unitDevotion)!=inclusive){
            container.erase(it);
        }
    }
    return *this;
}

GameObjectList &GameObjectList::ofClass(UnitClass unitClass, bool inclusive) {
    for(auto it = container.begin();it!=container.end();it++){
        if(((*it).getUnitClass()==unitClass)!=inclusive){
            container.erase(it);
        }
    }
    return *this;
}

GameObjectList &GameObjectList::ofType(UnitType unitType, bool inclusive) {
    for(auto it = container.begin();it!=container.end();it++){
        if((GameObject::classToType((*it).getUnitClass())==unitType)!=inclusive){
            container.erase(it);
        }
    }
    return *this;
}
