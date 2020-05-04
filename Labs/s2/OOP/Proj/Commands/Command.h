//
// Created by anton on 4/2/20.
//

#ifndef PROJ_COMMAND_H
#define PROJ_COMMAND_H

#include <string>
#include <cassert>

#include "../GameObject.h"
#include "../Mediator.h"


class Facade;

class Command {
protected:
    std::string title;
    Mediator* mediator;
    Facade* facade;
    bool userActions;
public:

    Command(Mediator *mediator, Facade *facade, bool userActions, std::string title = "");

    bool requiresUserActions() const;

    virtual bool execute() = 0;
    
    /*
     * yhohoiukyllkjhjjnn
    oootlrf
    llllte
    ujrik
    lmhfynjh
    kkkk))
    kkk
    *$#@
    87775,(5588)
     hhjggg7897 (fth) 44" ,./tt
     yrrjj--//
     */


public:



};


#endif //PROJ_COMMAND_H
