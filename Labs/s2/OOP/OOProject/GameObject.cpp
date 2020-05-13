//
// Created by anton on 5/9/20.
//

#include "GameObject.h"

bool GameObject::isToBeRemoved() const {
    return toBeRemoved;
}

void GameObject::setToBeRemoved(bool toBeRemoved) {
    GameObject::toBeRemoved = toBeRemoved;
}

GameObject::GameObject(int x, int y, bool toBeRemoved, Devotion devotion, ObjectType objectType,
                       CommonClass objectClass,
                       int health, int armour, float dmgmul) : x(x), y(y), toBeRemoved(toBeRemoved), devotion(devotion),
                                                vitality(health,armour,dmgmul,this), objectType(objectType),objectClass(objectClass) {}

std::pair<int, int> GameObject::getCoords() {
    return std::pair<int, int>(x,y);
}

void GameObject::setCoords(int x, int y) {
    this->x = x;
    this->y = y;
}
