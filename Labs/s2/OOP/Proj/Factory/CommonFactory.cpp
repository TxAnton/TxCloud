//
// Created by anton on 2/22/20.
//

#include "CommonFactory.h"

CommonFactory::CommonFactory(Field *fld) {
    this->fld = fld;
    alphaFactory = new AlphaFactory(fld);
    betaFactory = new BetaFactory(fld);
    gammaFactory = new GammaFactory(fld);
    deltaFactory = new DeltaFactory(fld);
    epsilonFactory = new EpsilonFactory(fld);
    zetaFactory = new ZetaFactory(fld);
}

CommonFactory::~CommonFactory() {
    delete alphaFactory;
    delete betaFactory;
    delete gammaFactory;
    delete deltaFactory;
    delete epsilonFactory;
    delete zetaFactory;

}

GameObject *CommonFactory::createUnit(UnitClass _class, UnitDevotion devotion, int x, int y) {
    switch (_class) {

        case UnitClass::ALPHA: {

            return alphaFactory->createUnit(_class, devotion, x, y);
            break;
        }
        case UnitClass::BETA: {
            return betaFactory->createUnit(_class, devotion, x, y);
            break;
        }
        case UnitClass::GAMMA: {
            return gammaFactory->createUnit(_class, devotion, x, y);
            break;
        }
        case UnitClass::DELTA: {
            return deltaFactory->createUnit(_class, devotion, x, y);
            break;
        }
        case UnitClass::EPSILON: {
            return epsilonFactory->createUnit(_class, devotion, x, y);
            break;
        }
        case UnitClass::ZETA: {
            return zetaFactory->createUnit(_class, devotion, x, y);
            break;
        }
        case UnitClass::NO_CLASS:
            return nullptr;
        default:
            return nullptr;
    }

}
