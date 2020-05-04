//
// Created by anton on 4/2/20.
//

#ifndef PROJ_COMMANDSTEP_H
#define PROJ_COMMANDSTEP_H

#include "Command.h"

class CommandStep: public Command {
public:
    CommandStep(Mediator *mediator, Facade *facade, int srcX, int srcY, int dstX, int dstY);

    CommandStep(Mediator *mediator, Facade *facade);

    bool execute() override;

private:
    int srcX,srcY;
    int dstX,dstY;
public:

};


#endif //PROJ_COMMANDSTEP_H
