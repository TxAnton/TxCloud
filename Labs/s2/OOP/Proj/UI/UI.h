//
// Created by anton on 4/3/20.
//

#ifndef PROJ_UI_H
#define PROJ_UI_H

#include <string>

class UI {
public:
    virtual void slNotify(std::string message) = 0;
    virtual std::pair<int, int> slGetCoords(std::string message) = 0;
};


#endif //PROJ_UI_H
