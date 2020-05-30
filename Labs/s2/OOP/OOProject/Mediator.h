//
// Created by anton on 5/23/20.
//

#ifndef OOPROJECT_MEDIATOR_H
#define OOPROJECT_MEDIATOR_H

#include <memory>

#include "Field.h"
#include "Factory/CommonFactory.h"

class Mediator {
private:
    std::shared_ptr<Field> field;
    std::shared_ptr<CommonFactory> factory;
    std::pair<int,int> selectionA;
    std::pair<int,int> selectionB;
public:
    Mediator(const std::shared_ptr<Field> &field, const std::shared_ptr<CommonFactory> &factory);

    const std::pair<int, int> &getSelectionA() const;

    void setSelectionA(const std::pair<int, int> &selectionA);

    const std::pair<int, int> &getSelectionB() const;

    void setSelectionB(const std::pair<int, int> &selectionB);

public:
    int distance();

    int getSteepnessAtB();

    bool createObject(int x, int y, Devotion devotion, CommonClass objectClass);

    bool step();
    bool act();
};


#endif //OOPROJECT_MEDIATOR_H

