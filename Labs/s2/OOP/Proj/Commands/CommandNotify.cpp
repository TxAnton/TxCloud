//
// Created by anton on 4/3/20.
//

#include "CommandNotify.h"
#include "../Facade.h"


CommandNotify::CommandNotify(Mediator *mediator, Facade *facade, bool userActions, const std::string message,
                             const std::string &title) : Command(mediator, facade, userActions, title),
                                                           message(message) {}

bool CommandNotify::execute() {
    facade->sendUIMessage(message);
    return true;
}