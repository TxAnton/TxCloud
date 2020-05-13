//
// Created by anton on 5/10/20.
//

#ifndef OOPROJECT_FIELD_H
#define OOPROJECT_FIELD_H

#include <memory>
#include "Cell.h"

class Field {
    Cell** content;
    int objLimit;
    int onjCnt;
    int height;
    int width;
};


#endif //OOPROJECT_FIELD_H
