//
// Created by anton on 2/12/20.
//

#ifndef PROJ_ALPHA_H
#define PROJ_ALPHA_H


#include "God.h"
#include "../Base.h"

class Alpha : public God, public Base {

public:
    Alpha(Field *fld, int x, int y, int health = 0, UnitDevotion devotion = UnitDevotion::NEUTER, bool active = false);

    int getUnitLim() override;

    void setUnitLim(int unitLim1) override;

    bool spawnAt(UnitClass unitClass, int x, int y) override;

    //Alpha(Field *fld, int x, int y, int health, UnitDevotion devotion, bool active, CommonFactory *factory, int unitLim);

    UnitClass getUnitClass() override;

    void deathEvent() override;

    void summon(Direction dir) override;

    wchar_t toChar() override;

    bool isValidStep(int x, int y) override;

    bool step(int x, int y) override;

    virtual GameObject &operator+=(const LandscapeProxy &b);

//    void recieveDeath(GameObject *gameObject) override;

private:

    int unitLim;

    int unitCnt;

    /*
    char toChar();

    bool isValidStep(int x, int y);

    bool step(int x, int y);
     */

};


#endif //PROJ_ALPHA_H
