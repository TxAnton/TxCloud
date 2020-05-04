//
// Created by anton on 4/3/20.
//

#ifndef PROJ_COMMANDPLACE_H
#define PROJ_COMMANDPLACE_H

#include "../UnitProps.h"

#include "Command.h"

class CommandPlace: public Command {
public:
    CommandPlace(Mediator *mediator, Facade *facade, bool userActions, const std::string &title, UnitClass unitClass,
                 UnitDevotion devotion, int x, int y);

    bool execute() override;

private:
    UnitClass unitClass;
    UnitDevotion devotion;
    int x;
    int y;

};


#endif //PROJ_COMMANDPLACE_H
