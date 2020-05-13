//
// Created by anton on 5/9/20.
//

#include "Vitality.h"

Vitality::Vitality(int health, int armour, float dmgMul, GameObject *master) : health(health), armour(armour),
                                                                               dmgMul(dmgMul), master(master) {}
