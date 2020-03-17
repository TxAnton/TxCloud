//
// Created by anton on 3/17/20.
//

#include "FieldCellProxy.h"

FieldCellProxy::FieldCellProxy(Mediator *mediator1, int x, int y) {
    mediator = mediator1;
}

LandscapeProxy FieldCellProxy::getLandscape() const {
    return LandscapeProxy(mediator, x, y);
}

GameObject *FieldCellProxy::getObject() const {
    return mediator->getObjAt(x, y);
}
