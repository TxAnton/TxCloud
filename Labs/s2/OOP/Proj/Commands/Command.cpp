//
// Created by anton on 4/2/20.
//

#include "Command.h"

bool Command::requiresUserActions() const {
    return userActions;
}

Command::Command(const Mediator &mediator, bool userActions) : mediator(mediator), userActions(userActions) {}
