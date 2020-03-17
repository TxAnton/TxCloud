//
// Created by anton on 3/17/20.
//

#ifndef PROJ_FIELDCELLPROXY_H
#define PROJ_FIELDCELLPROXY_H

#include "Mediator.h"
#include "LandscapeProxy.h"


class GameObject;

class FieldCellProxy {
private:
    Mediator *mediator;
public:
    int x;
    int y;

    FieldCellProxy(Mediator *mediator1, int x = 0, int y = 0);

    LandscapeProxy getLandscape() const;

    GameObject *getObject() const;
};


#endif //PROJ_FIELDCELLPROXY_H
