//
// Created by anton on 3/4/20.
//

#ifndef PROJ_ENTITYSTONE_H
#define PROJ_ENTITYSTONE_H

#include "Entity.h"

class EntityStone : public Entity {
public:
    wchar_t toChar() override;

    bool die(GameObject *src) override;

};


#endif //PROJ_ENTITYSTONE_H
