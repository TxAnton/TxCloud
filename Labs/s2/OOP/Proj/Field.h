//
// Created by anton on 2/11/20.
//

#ifndef PROJ_FIELD_H
#define PROJ_FIELD_H

#include<string>
#include<assert.h>
//#include "Game.h"
#include "GameObject.h"

class Field {
private:
    GameObject ***content;
    int width;
    int height;
    int objLimit;
public:
    //Field(int width, int height);

    Field(int width, int height, int objLimit);

    void getSize(int &width, int &height);

    void resetSize(int width, int height);

    GameObject *getAt(int x, int y);

    void setAt(GameObject &obj, int x, int y);

    void removeAt(int x, int y);

    void swap(int x1, int y1, int x2, int y2);

    std::string toString();
};


#endif //PROJ_FIELD_H
