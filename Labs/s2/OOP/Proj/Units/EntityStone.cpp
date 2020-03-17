//
// Created by anton on 3/4/20.
//

#include "EntityStone.h"

wchar_t EntityStone::toChar() {
    return 0;
}

bool EntityStone::die(GameObject *src) {
    return GameObject::die(src);
}
