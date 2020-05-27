//
// Created by anton on 5/26/20.
//

#ifndef OOPROJECT_COMMONFACTORY_H
#define OOPROJECT_COMMONFACTORY_H

#include <memory>

#include "Unit/AgileFactory.h"
#include "Unit/MarathonerFactory.h"
#include "Unit/PowerfulFactory.h"
#include "Unit/RangerFactory.h"
#include "Unit/VampireFactory.h"
#include "Unit/ToughFactory.h"
#include "Terrain/HollyFactory.h"
#include "Terrain/SpikyFactory.h"
#include "Terrain/SteepFactory.h"


class CommonFactory {
public:
    CommonFactory();

    /*
    CommonFactory(int health, int enhancedHealth, int armour, float dmgmul, float vampiricMultiplyer,
                  int abPower, int enhancedPower, int abRange, int enhancedAbRange, int mbAgility,
                  int enhancedAgility, int mbRange, int enhancedMbRange);
                  */
    std::shared_ptr<GameObject> createObject(int x, int y, Devotion devotion, CommonClass objectClass);
private:
    void initFactories();
    void initParams(int health, int enhancedHealth, int armour, float dmgmul, float vampiricMultiplyer,
                    int abPower, int enhancedPower, int abRange, int enhancedAbRange, int mbAgility,
                    int enhancedAgility, int mbRange, int enhancedMbRange, int steepness,
                    int enhancedSteepness, int terrainDamage, int terrainHeal);
private:
    std::unique_ptr<RangerFactory> rangerFactory;
    std::unique_ptr<PowerfulFactory> powerfulFactory;
    std::unique_ptr<AgileFactory> agileFactory;
    std::unique_ptr<MarathonerFactory> marathonerFactory;
    std::unique_ptr<ToughFactory> toughFactory;
    std::unique_ptr<VampireFactory> vampireFactory;
    std::unique_ptr<SpikyFactory> spikyFactory;
    std::unique_ptr<SteepFactory> steepFactory;
    std::unique_ptr<HollyFactory> hollyFactory;

    int health = 100;
    int enhancedHealth;
    int armour = 100;
    float dmgmul = 1;
    float vampiricMultiplyer=.8;
    int abPower=50;
    int enhancedPower=100;
    int abRange=2;
    int enhancedAbRange=5;
    int mbAgility=5;
    int enhancedAgility=10;
    int mbRange=5;
    int enhancedMbRange=10;

    int steepness = 2;
    int enhancedSteepness = 7;
    int terrainDamage = 25;
    int terrainHeal = 25;







};


#endif //OOPROJECT_COMMONFACTORY_H
