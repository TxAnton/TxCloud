//
// Created by anton on 4/2/20.
//

#include "cassert"

#include "Facade.h"


const std::pair<int, int> &Facade::getSelectionA() const {
    return selectionA;
}

void Facade::setSelectionA(const std::pair<int, int> &selectionA) {
    Facade::selectionA = selectionA;
}

const std::pair<int, int> &Facade::getSelectionB() const {
    return selectionB;
}

void Facade::setSelectionB(const std::pair<int, int> &selectionB) {
    Facade::selectionB = selectionB;
}

const std::pair<int, int> &Facade::getSelectionC() const {
    return selectionC;
}

void Facade::setSelectionC(const std::pair<int, int> &selectionC) {
    Facade::selectionC = selectionC;
}



Facade::Facade() {
    selectionA={0,0};
    selectionB={0,0};
}

bool Facade::popCommand() {
    if(commandQueue.empty())return false;
    commandQueue.pop_back();
    return true;
}

Command &Facade::topCommand() {
    assert(!commandQueue.empty());
    return *commandQueue.back();
}

void Facade::execQueue() {
    while(!empty()){
        //TODO LOG
        topCommand().execute();
        assert(popCommand());
    }

}

bool Facade::empty() const {
    return commandQueue.empty();
}

std::pair<int, int> Facade::reqUICoords(std::string message) {
    return std::pair<int, int>();
}

void Facade::sendUIMessage(std::string message) {

}
void Facade::pushCommand(std::shared_ptr<Command> c) {
    commandQueue.push_back(c);
}

void Facade::pushCommand(Command *c) {
    commandQueue.push_back(std::shared_ptr<Command>(c));
}


