//
// Created by anton on 3/4/20.
//

#ifndef PROJ_ENTITYFIRE_H
#define PROJ_ENTITYFIRE_H

#include "Entity.h"

class EntityFire : public Entity {
public:
    wchar_t toChar() override;

    bool die(GameObject *src) override;

};


#endif //PROJ_ENTITYFIRE_H
