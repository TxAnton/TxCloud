//
// Created by anton on 4/6/20.
//

#ifndef PROJ_CONSOLEUI_H
#define PROJ_CONSOLEUI_H

#include <utility>
#include "UI.h"

class ConsoleUI:public UI {
public:
    void slNotify(std::string message) override;

    std::pair<int, int> slGetCoords(std::string message) override;


};


#endif //PROJ_CONSOLEUI_H
