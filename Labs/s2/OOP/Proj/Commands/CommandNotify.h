//
// Created by anton on 4/3/20.
//

#ifndef PROJ_COMMANDNOTIFY_H
#define PROJ_COMMANDNOTIFY_H

#include "Command.h"

class CommandNotify:public Command {
public:
    CommandNotify(Mediator *mediator, Facade *facade, bool userActions, const std::string message,
                  const std::string &title = "Notify");

    bool execute() override;

private:


    std::string message;





};


#endif //PROJ_COMMANDNOTIFY_H
