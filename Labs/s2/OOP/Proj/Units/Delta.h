//
// Created by anton on 2/12/20.
//

#ifndef PROJ_DELTA_H
#define PROJ_DELTA_H


#include "Mage.h"

class Delta : public Mage {
public:
    Delta(Field *fld, int x, int y, int health = 0, UnitDevotion devotion = UnitDevotion::NEUTER, bool active = false,
          int girdle = -1);

private:
    wchar_t toChar() override;

    UnitClass getUnitClass() override;

    int getPower() override;

    bool isValidStep(int x, int y) override;

    bool step(int x, int y) override;

    virtual GameObject &operator+=(const LandscapeProxy &b);


private:
    int girdle;

};


#endif //PROJ_DELTA_H
