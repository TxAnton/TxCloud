//
// Created by anton on 4/2/20.
//

#include <cassert>

#include "CommandStep.h"

#include "CommonComands.h"

//User actions:By selection
//ELse: by args

CommandStep::CommandStep(Mediator *mediator, Facade *facade, int srcX, int srcY, int dstX, int dstY)
        : Command(mediator, facade, false, "CommandStep"), srcX(srcX), srcY(srcY), dstX(dstX), dstY(dstY) {}

CommandStep::CommandStep(Mediator *mediator, Facade *facade): Command(mediator, facade, true, "CommandStep") , srcX(-1), srcY(-1), dstX(-1), dstY(-1) {}

bool CommandStep::execute() {
    if(userActions) {
        auto selA = facade->getSelectionA();
        auto selB = facade->getSelectionB();
        srcX = selA.first;
        srcY = selA.second;
        dstX = selB.first;
        dstY = selB.second;
    }

    if(!(mediator->isValidCoords(srcX,srcY) && mediator->isValidCoords(dstX,dstY))){
        facade->pushCommand(new CommandNotify(mediator,facade,false,"Wrong coords"));
        return false;
    }else{
        GameObject* src = mediator->getObjAt(srcX,srcY);
        GameObject* dst = mediator->getObjAt(dstX,dstY);

        if(!src->isValidStep(dstX,dstY)){
            facade->pushCommand(new CommandNotify(mediator,facade,false,"Invalid step"));
            return false;
        } else if(!dst){
            assert(mediator->moveObj(srcX,srcY,dstX,dstY));
        } else {
            assert(mediator->moveObj(srcX,srcY,dstX,dstY));
        }

    }
    return false;
}



