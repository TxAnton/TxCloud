//
// Created by anton on 3/4/20.
//

#ifndef PROJ_ENTITYTREE_H
#define PROJ_ENTITYTREE_H

#include "Entity.h"

class EntityTree : public Entity {
public:
    wchar_t toChar() override;

    bool die(GameObject *src) override;

};


#endif //PROJ_ENTITYTREE_H
