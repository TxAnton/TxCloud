//
// Created by anton on 2/18/20.
//

#ifndef PROJ_UNITFACTORY_H
#define PROJ_UNITFACTORY_H

#include "GameObject.h"
#include "Units/God.h"
#include "Units/Mage.h"
#include "Units/Fighter.h"
#include "Units/Alpha.h"
#include "Units/Beta.h"
#include "Units/Gamma.h"
#include "Units/Delta.h"
#include "Units/Epsilon.h"
#include "Units/Zeta.h"
class UnitFactory {
private:
    Field* fld;
public:
    UnitFactory(Field* fld);

    virtual ~UnitFactory();

    GameObject* createUnit(UnitClass _class,UnitDevotion  devotion = UnitDevotion ::NEUTER, int x=-1, int y=-1);

};


#endif //PROJ_UNITFACTORY_H
