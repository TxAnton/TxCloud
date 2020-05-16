//
// Created by anton on 5/10/20.
//

#include "Field.h"

Field::Field(int objLimit, int height, int width) : objLimit(objLimit),
                                                    height(height), width(width), objCnt(0) {
    content = new Cell*[height];
    for(int i = 0;i<height;i++){
        content[i] = new Cell[width]();
    }
}

std::shared_ptr<Unit> Field::getUnitAt(int x, int y) {
    return content[y][x].getUnit();
}

void Field::setUnitAt(std::shared_ptr<Unit> unit, int x, int y) {
    if(!unit && getUnitAt(x,y))objCnt--;
    if(unit && !getUnitAt(x,y)){
        objCnt++;
        if(objCnt>objLimit)onLimitExceeded();
    }
    content[y][x].setUnit(unit);
}

std::shared_ptr<TerrainProxy> Field::getTerrainAt(int x, int y) {
    return content[y][x].getTerrain();
}

void Field::setTerrainAt(std::shared_ptr<TerrainProxy> terrain, int x, int y) {
    content[y][x].setTerrain(terrain);
}

std::shared_ptr<Entity> Field::getEntityAt(int x, int y) {
    return content[y][x].getEntity();
}

void Field::setEntityAt(std::shared_ptr<Entity> entity, int x, int y) {
    content[y][x].setEntity(entity);
}

void Field::onLimitExceeded() {
    //TODO add exception here!!!
    assert(0 && "object limit exceeded");
}

bool Field::objSwap(int x1, int y1, int x2, int y2) {
    //True if any one is occupied
    //False if neither of both are occupied

    auto unit1 = getUnitAt(x1,y1);
    auto unit2 = getUnitAt(x2,y2);
    auto foo = unit1.use_count();
    foo = unit2.use_count();
    bool occ1 = unit1!=0;
    bool occ2 = unit2!=0;
    if(occ1){
        if(occ2){
            setUnitAt(std::shared_ptr<Unit>(unit2),x1,y1);
            setUnitAt(std::shared_ptr<Unit>(unit1),x2,y2);
            return false;
        }else{
            //Unit* tmp = &(*unit1);
            setUnitAt(std::shared_ptr<Unit>(unit2),x1,y1);
            setUnitAt(std::shared_ptr<Unit>(unit1),x2,y2);;
            return true;
        }
    } else{
        if(occ2){
            setUnitAt(std::shared_ptr<Unit>(unit2),x1,y1);
            setUnitAt(std::shared_ptr<Unit>(unit1),x2,y2);
            return true;
        }else{
            return false;
        }
    }
}

std::wstring Field::toWString() {
    std::wstring str = L"";
    for (int j = height; j >= -1; j--) {
        for (int i = -1; i <= width; i++) {
            if (i == -1 || i == width) {
                if (j == -1 || j == height) str += L"#";//Corner element
                else {//Left/right Border
                    str += L'a' + j;
                }
            } else if (j == -1 || j == height) {
                str += L'1' + i;
            } else {
                if (content[i][j].getUnit() == nullptr)str += L" ";
                else {
                    str += content[i][j].getUnit()->flyWeight->symbol;
                }
            }
        }
        str += L"\n";
    }
    return str;
}

Field::Field(const Field &src) {
    if(this != &src) {
        this->objLimit = src.objLimit;
        this->objCnt = src.objCnt;
        this->width = src.width;
        this->height = src.height;
        content = new Cell *[height];
        for (int i = 0; i < src.height; i++) {
            content[i] = new Cell[width]();
            for (int j = 0; j < width; j++) {
                content[i][j] = Cell(src.content[i][j]);
            }
        }
    }
}

Field &Field::operator=(Field &&other) {
    std::swap(*this, other);
    return *this;
}
