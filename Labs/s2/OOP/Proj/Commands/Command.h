//
// Created by anton on 4/2/20.
//

#ifndef PROJ_COMMAND_H
#define PROJ_COMMAND_H


#include "Mediator.h"

class Command {
private:
    Mediator mediator;
    bool userActions;
public:


    Command(const Mediator &mediator, bool userActions);

    bool requiresUserActions() const;

    virtual bool execute() = 0;

public:




};


#endif //PROJ_COMMAND_H
