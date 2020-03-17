//
// Created by anton on 3/4/20.
//

#ifndef PROJ_ENTITYBUSH_H
#define PROJ_ENTITYBUSH_H

#include "Entity.h"

class EntityBush:public Entity {
    wchar_t toChar() override;

    bool die(GameObject *src) override;

public:
    GameObject &operator+=(const LandscapeProxy &b) override;

};


#endif //PROJ_ENTITYBUSH_H
