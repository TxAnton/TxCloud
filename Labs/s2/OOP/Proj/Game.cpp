//
// Created by anton on 2/11/20.
//

#include "Game.h"

//#include "GameObject.h"
Mediator *GameObject::mediator;//TODO MASSIVE CRUTCH HERE


Game::Game(int fieldWidth, int fieldHeight) {
    field = new Field(fieldWidth, fieldHeight, fieldHeight * fieldWidth);
    //factory = new CommonFactory(field);

    mediator = new Mediator(field);
    GameObject::mediator = mediator;
}

void Game::run() {

    mediator->createAt(UnitClass::ALPHA, UnitDevotion::LIGHT, 5, 5);

    std::cout << "Set unit" << std::endl;
    //GameObject *go = factory->createUnit(UnitClass::ALPHA);
//    objVector.push_back(go);
    //field->setAt(*go, 5, 5);
    auto obj = mediator->getObjAt(5, 5);
    dynamic_cast<Alpha *>(obj)->spawnAt(UnitClass::ZETA, 1, 1);


    std::wcout << field->toWString();

    mediator->moveObj(5, 5, 1, 1);

    std::wcout << field->toWString();

    std::cout << (int) (obj->getUnitClass()) << std::endl;
    return;
    /*
    std::cout << "Move unit" << std::endl;
    field->move(5, 5, 7, 7);
    std::wcout << field->toWString();


    std::cout << "reset" << std::endl;
    field->resetField();
    std::wcout << field->toWString();


    std::cout << "Set unit" << std::endl;
    go = factory->createUnit(UnitClass::ALPHA);
//    objVector.push_back(go);
    field->setAt(*go, 5, 5);
    std::wcout << field->toWString();

    std::cout << "Set unit" << std::endl;
    go = factory->createUnit(UnitClass::BETA);
//    objVector.push_back(go);
    field->setAt(*go, 1, 1);
    std::wcout << field->toWString();

    std::cout << "Cut unit" << std::endl;
    field->move(1, 1, 5, 5);
    std::wcout << field->toWString();


    std::cout << "reset" << std::endl;
    field->resetField();
    std::wcout << field->toWString();

    std::cout << "Set unit" << std::endl;
    go = factory->createUnit(UnitClass::ALPHA);
//    objVector.push_back(go);
    field->setAt(*go, 5, 5);
    std::wcout << field->toWString();

    std::cout << "Set unit" << std::endl;
    go = factory->createUnit(UnitClass::BETA);
//    objVector.push_back(go);
    field->setAt(*go, 1, 1);
    std::wcout << field->toWString();

    std::cout << "Set unit" << std::endl;
    go = factory->createUnit(UnitClass::GAMMA);
//    objVector.push_back(go);
    field->setAt(*go, 6, 1);
    std::wcout << field->toWString();

    std::cout << "Set unit" << std::endl;
    go = factory->createUnit(UnitClass::ZETA);
//    objVector.push_back(go);
    field->setAt(*go, 3, 4);
    std::wcout << field->toWString();

    std::cout << "Swap unit" << std::endl;
    field->swap(5, 5, 1, 1);
    std::wcout << field->toWString();

*/

    //delete field;
    //field = new Field(fieldWidth, fieldHeight, fieldHeight * fieldWidth);

}

Game::~Game() {

}
