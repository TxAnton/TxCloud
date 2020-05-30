//
// Created by anton on 5/23/20.
//

#include "Mediator.h"

const std::pair<int, int> &Mediator::getSelectionA() const {
    return selectionA;
}

void Mediator::setSelectionA(const std::pair<int, int> &selectionA) {
    Mediator::selectionA = selectionA;
}

const std::pair<int, int> &Mediator::getSelectionB() const {
    return selectionB;
}

void Mediator::setSelectionB(const std::pair<int, int> &selectionB) {
    Mediator::selectionB = selectionB;
}

int Mediator::distance() {
    return abs(selectionA.first-selectionB.first)+abs(selectionA.second-selectionB.second);
}

int Mediator::getSteepnessAtB() {
    //TODO exeption coords out of field
    return field->getTerrainAt(selectionB.first,selectionB.second)->getSteepness();
}

bool Mediator::step() {
    bool flag = true;
    auto A = field->getUnitAt(selectionA.first,selectionA.second);
    if(!A)return false;//NoUnit
    if(!(A->canStep(selectionB.first,selectionB.second)))return false;//Cant step
    auto B = field->getUnitAt(selectionB.first,selectionB.second);
    if(B)return false;//Dest occupied

    if(flag){
        auto Bt = field->getTerrainAt(selectionB.first,selectionB.second);
        assert(Bt);//TODO exeption no terrain
        Bt->restep(A);
        if(A->canStep(selectionB.first,selectionB.second)){
            A->step(std::static_pointer_cast<GameObject>(Bt));
            //field->objSwap(selectionA.first,selectionA.second,selectionB.first,selectionB.second);
        }else flag= false;
    }

    auto Be = field->getEntityAt(selectionB.first, selectionB.second);
    if(flag) {
        if (Be) {
            Be->restep(A);
            if (A->canStep(selectionB.first, selectionB.second)) {
                A->step(Be);
            } else flag = false;
        }
    }

    if(flag){
        field->objSwap(selectionA.first,selectionA.second,selectionB.first,selectionB.second);
        A->setCoords(selectionB);
    }

    A->setBlocked(false);
    if(A->isToBeRemoved())
        field->setUnitAt(std::shared_ptr<Unit>(nullptr),selectionA.first,selectionA.first);
    if(Be&&Be->isToBeRemoved())
        field->setEntityAt(std::shared_ptr<Entity>(nullptr),selectionB.first,selectionB.first);

    return true;
}

bool Mediator::act() {
    bool flag = true;
    auto A = field->getUnitAt(selectionA.first,selectionA.second);
    if(!A)return false;//NoUnit
    if(!(A->canAct(selectionB.first,selectionB.second)))return false;//Cant step

    auto B = field->getUnitAt(selectionB.first,selectionB.second);
    if(B){
        A->act(B);
        B->react(A);
        A->setBlocked(false);
        B->setBlocked(false);
        if(A->isToBeRemoved())field->setUnitAt(std::shared_ptr<Unit>(nullptr),selectionA.first,selectionA.first);
        if(B->isToBeRemoved())field->setUnitAt(std::shared_ptr<Unit>(nullptr),selectionB.first,selectionB.first);
        return true;

    }else{
        auto Be = field->getEntityAt(selectionB.first,selectionB.second);
        if(Be){
            //A->act(Be);
            Be+=A;
            Be->react(A);
            A->setBlocked(false);
            if(A->isToBeRemoved())field->setUnitAt(std::shared_ptr<Unit>(nullptr),selectionA.first,selectionA.first);
            if(Be->isToBeRemoved())field->setEntityAt(std::shared_ptr<Entity>(nullptr),selectionB.first,selectionB.first);
            return true;
        }else{
            return false;//Nothing to act on
        }
    }
    assert(0);
}

Mediator::Mediator(const std::shared_ptr<Field> &field, const std::shared_ptr<CommonFactory> &factory) : field(field),
                                                                                                         factory(factory) {}

bool Mediator::createObject(int x, int y, Devotion devotion, CommonClass objectClass) {
    auto object = factory->createObject(x,y,devotion,objectClass);

    ObjectType  ot = classToType(objectClass);
    switch (ot){

        case ObjectType::Unit:{
            auto cObject = std::dynamic_pointer_cast<Unit>(object);
            assert(cObject);
            field->setUnitAt(cObject,x,y);
            break;
        }
        case ObjectType::Entity:{
            auto cObject = std::dynamic_pointer_cast<Entity>(object);
            assert(cObject);
            field->setEntityAt(cObject,x,y);
            break;
        }
        case ObjectType::Terrain:{
            object.reset();
            auto cObject = std::make_shared<TerrainProxy>(x,y,classToTerrain(objectClass),factory);
            assert(cObject);
            field->setTerrainAt(cObject,x,y);
            break;
        }
        /*
        case ObjectType::Base:{
            auto cObject = std::static_pointer_cast<Unit>(object);
            //auto cObject = std::dynamic_pointer_cast<Unit>(object);
            assert(cObject);
            field->setUnitAt(cObject,x,y);
            break;
        }
        */
        case ObjectType::NONE:assert(0);//TODO exception creating NONE class object
    }
    return false;
}
