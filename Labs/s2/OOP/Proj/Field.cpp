//
// Created by anton on 2/11/20.
//

#include "Field.h"

Field::Field(int width, int height, int objLimit){// : width(width), height(height), objLimit(objLimit)
    this->width=width;
    this->height=height;
    this->objLimit=objLimit;
    content = new GameObject**[width];
    for(int i=0;i<width;i++){
        content[i] = new GameObject*[height];
        for(int j = 0;j<height;j++){
            content[i][j]=nullptr;
        }
    }

}

void Field::getSize(int &width, int &height) {
    width=this->width;
    height=this->height;
}

void Field::resetSize(int width, int height) {
    //TODO
}

GameObject *Field::getAt(int x, int y) {
    assert(0<=x && x<width);
    assert(0<=y && y<height);
    return content[x][y];
}

void Field::setAt(GameObject &obj, int x, int y) {
    assert(0<=x && x<width);
    assert(0<=y && y<height);
    content[x][y]=&obj;
}

void Field::removeAt(int x, int y) {
    assert(0<=x && x<width);
    assert(0<=y && y<height);
    content[x][y]= nullptr;
}

void Field::swap(int x1, int y1, int x2, int y2) {
    assert(0<=x1 && x1<width);
    assert(0<=y1 && y1<height);
    assert(0<=x2 && x2<width);
    assert(0<=y2 && y2<height);
    GameObject* dest = content[x2][y2];
    content[x2][y2] = content[x1][y1];
    content[x1][y1] = dest;
}

std::string Field::toString() {//top-left to bottom-right
    std::string str;
    for(int j=height;j>=-1;j--){
        for(int i=-1;i<=width;i++){
            if(i==-1 || i==width){
                if(j==-1) str+="#";//Corner element
                else{//Left/right Border
                    str+='a'+j;
                }
            }else if(j==-1 || j==height){
                str+='1'+i;
            }
            else{
                if(content[i][j]==nullptr)str+=" ";
                else{
                    str+=content[i][j]->toChar();
                }
            }
        }
        str+="\n";
    }
    return str;
}
