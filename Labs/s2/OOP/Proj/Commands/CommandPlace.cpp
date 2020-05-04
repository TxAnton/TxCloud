//
// Created by anton on 4/3/20.
//

#include <memory>

#include "CommandPlace.h"

#include "CommonComands.h"

#include "../Facade.h"


bool CommandPlace::execute() {
    if(mediator->getObjAt(x,y)){
        facade->pushCommand( std::dynamic_pointer_cast<Command>( std::shared_ptr<CommandNotify>(new CommandNotify(mediator, facade, false,"Object already there"))) );
        ///Notify: Object already there
        return false;
    }else{
        mediator->createAt(unitClass,devotion,x,y);
    }
}

CommandPlace::CommandPlace(Mediator *mediator, Facade *facade, bool userActions, const std::string &title,
                           UnitClass unitClass, UnitDevotion devotion, int x, int y) : Command(mediator, facade,
                                                                                               userActions, "Place"),
                                                                                       unitClass(unitClass),
                                                                                       devotion(devotion), x(x), y(y) {}
