//
// Created by anton on 3/4/20.
//

#include "EntityFire.h"

wchar_t EntityFire::toChar() {
    return 0;
}

bool EntityFire::die(GameObject *src) {
    return GameObject::die(src);
}
