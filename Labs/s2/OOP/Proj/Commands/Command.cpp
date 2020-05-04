//
// Created by anton on 4/2/20.
//

#include "Command.h"

bool Command::requiresUserActions() const {
    return userActions;
}

Command::Command(Mediator *mediator, Facade *facade, bool userActions, std::string title)
        : mediator(mediator), facade(facade),
          userActions(userActions), title(title) {}

