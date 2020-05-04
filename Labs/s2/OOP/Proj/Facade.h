//
// Created by anton on 4/2/20.
//

#ifndef PROJ_FACADE_H
#define PROJ_FACADE_H


#include <vector>
#include <memory>

#include "Mediator.h"
#include "Commands/Command.h"
#include "UI/ConsoleUI.h"

class Facade {
private:
    Mediator* mediator;
    UI* ui;

    std::vector<std::shared_ptr<Command>> commandQueue;

    std::pair<int,int> selectionA;
    std::pair<int,int> selectionB;
    std::pair<int,int> selectionC;
public:
    const std::pair<int, int> &getSelectionC() const;

    void setSelectionC(const std::pair<int, int> &selectionC);


public:
    Facade();

    const std::pair<int, int> &getSelectionA() const;

    void setSelectionA(const std::pair<int, int> &selectionA);

    const std::pair<int, int> &getSelectionB() const;

    void setSelectionB(const std::pair<int, int> &selectionB);


private:
    bool popCommand();
    Command& topCommand();

public:
    bool empty() const;
    void pushCommand(std::shared_ptr<Command> c);
    void pushCommand(Command* c);
    void execQueue();

public:

    std::pair<int,int> reqUICoords(std::string message);
    void sendUIMessage(std::string message);
};


#endif //PROJ_FACADE_H
