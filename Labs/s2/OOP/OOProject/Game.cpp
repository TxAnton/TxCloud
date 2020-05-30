//
// Created by anton on 5/9/20.
//

#include "Game.h"
#include "GameObject/Unit/TheTough.h"
#include "GameObject/Entity/PitEntity.h"
#include "GameObject/Terrain/HollyTerrain.h"

Game* Game::instance = nullptr;

Game &Game::getInstance() {
    if(instance== nullptr){
        instance = new Game(9,9);
    }
    return *instance;
}

void Game::demo() {

    std::string s1 = "foo";
    std::string s2 = "bar";


    s2 = "foo";

    std::wcout<<field->toWString();

    mediator->createObject(1,1,Devotion::Light,CommonClass::Base);

    mediator->createObject(2,2,Devotion::Light,CommonClass::TheMarathoner);

    mediator->createObject(3,3,Devotion::Light,CommonClass::HealEntity);

    //mediator->createObject(8,8,Devotion::Dark,CommonClass::Base);

    mediator->setSelectionA({2,2});
    mediator->setSelectionB({3,3});

    std::wcout<<field->toWString();

    std::cout<<field->getUnitAt(2,2)->getVitality().getHealth()<<std::endl;
    std::cout<<mediator->step()<<std::endl;
    std::cout<<field->getUnitAt(3,3)->getVitality().getHealth()<<std::endl;
    std::wcout<<field->toWString();
    //mediator->act();
    //mediator->act();







    return;

    auto terrain = new TerrainProxy(2, 2,TerrainType::SpikyTerrain,std::shared_ptr<CommonFactory>(factory));

    field->setTerrainAt(std::shared_ptr<TerrainProxy>(terrain),2,2);



    auto pit = factory->createObject(8,8,Devotion::Neuter,CommonClass::PitEntity);
    //field->setUnitAt(std::static_pointer_cast<Unit>(pit),8,8);
    field->setEntityAt(std::static_pointer_cast<Entity>(pit),8,8);



    auto base = factory->createObject(1,1,Devotion::Light,CommonClass::Base);

    field->setUnitAt(std::static_pointer_cast<Unit>(base),1,1);

    //std::static_pointer_cast<Unit>(factory->createObject(5,5,Devotion::Dark,CommonClass::TheTough));
    auto tough = factory->createObject(5,5,Devotion::Light,CommonClass::TheTough);
    //new TheTough(5,5,Devotion::Neuter,100,100,1,50,5,5,5)
    field->setUnitAt(std::static_pointer_cast<Unit>(tough),5,5);

    tough->getVitality().damage(195);

    terrain->restep(tough);

    //std::dynamic_pointer_cast<PitEntity>(pit)->restep(tough);

    std::cout<<base.use_count()<<std::endl;
/*
    auto uPtr = field->getUnitAt(5,5);
    auto vPtr = uPtr->getVitality();
    vPtr.damage(250);

    */
    //uPtr.reset();

    std::wcout<<field->toWString();


    field->objSwap(5, 5, 0, 0);

    std::wcout<<field->toWString();


    /*
    Unit* unit;
    unit = new Unit(5, 5, Devotion::Neuter, CommonClass::TheRanger, 100, 100, 1, 50, 5, 5, 5, UnitType::AbleUnit);
    unit->flyWeight={"TheUnit",'#'};

    std::cout<<unit->canStep(6,6);
*/

}

Game::Game(int width, int height) : width(width), height(height) {
    field = new Field(2*width*height,height,width);
    factory = new CommonFactory();
    mediator = new Mediator(std::shared_ptr<Field>(field),std::shared_ptr<CommonFactory>(factory));
    factory->setMediator(std::shared_ptr<Mediator>(mediator));
    //factory = new CommonFactory(std::shared_ptr<Mediator>(mediator));


    initField();

}

void Game::initField() {

    for(int i= 0;i<height; i++){
        for(int j = 0; j<width; j++){
            int s = (i+j)%3;
            switch (s){
             case 0:mediator->createObject(j,i,Devotion::Neuter,CommonClass::SpikyTerrain);break;
             case 1:mediator->createObject(j,i,Devotion::Neuter,CommonClass::SteepTerrain);break;
             case 2:mediator->createObject(j,i,Devotion::Neuter,CommonClass::HollyTerrain);break;
            }

            //bool b = mediator->createObject(j,i,Devotion::Neuter,CommonClass::SpikyTerrain);
        }
    }
}
