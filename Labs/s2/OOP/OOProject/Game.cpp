//
// Created by anton on 5/9/20.
//

#include "Game.h"

Game* Game::instance = nullptr;

Game &Game::getInstance() {
    if(instance== nullptr){
        instance = new Game;
    }
    return *instance;
}

void Game::demo() {

    std::string s1 = "foo";
    std::string s2 = "bar";


    s2 = "foo";

    field = new Field(10,9,9);

    field->setUnitAt(std::make_shared<Unit>(5, 5, Devotion::Neuter, CommonClass::Unit1, 100, 100, 1, 50, 5, 5, 5, UnitType::AbleUnit),5,5);

    std::wcout<<field->toWString();


    field->objSwap(5, 5, 0, 0);

    std::wcout<<field->toWString();


    /*
    Unit* unit;
    unit = new Unit(5, 5, Devotion::Neuter, CommonClass::Unit1, 100, 100, 1, 50, 5, 5, 5, UnitType::AbleUnit);
    unit->flyWeight={"TheUnit",'#'};

    std::cout<<unit->canStep(6,6);
*/

}
