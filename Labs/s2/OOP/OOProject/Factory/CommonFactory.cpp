//
// Created by anton on 5/26/20.
//

#include "CommonFactory.h"

CommonFactory::CommonFactory() {
    initParams(100,200,100,1,.8,50,100,2,5,5,10,5,10,2,7,25,25);
    initFactories();
}

void CommonFactory::initFactories() {
    rangerFactory=std::make_unique<RangerFactory>(health,armour,dmgmul,abPower,abRange,mbAgility,mbRange,enhancedAbRange);
    powerfulFactory=std::make_unique<PowerfulFactory>(health,armour,dmgmul,abPower,abRange,mbAgility,mbRange,enhancedPower);
    agileFactory=std::make_unique<AgileFactory>(health,armour,dmgmul,abPower,abRange,mbAgility,mbRange,enhancedAgility);
    marathonerFactory=std::make_unique<MarathonerFactory>(health,armour,dmgmul,abPower,abRange,mbAgility,mbRange,enhancedMbRange);
    toughFactory=std::make_unique<ToughFactory>(health,armour,dmgmul,abPower,abRange,mbAgility,mbRange,enhancedHealth);
    vampireFactory=std::make_unique<VampireFactory>(health,armour,dmgmul,abPower,abRange,mbAgility,mbRange,vampiricMultiplyer);
    spikyFactory=std::make_unique<SpikyFactory>(steepness,terrainDamage);
    steepFactory=std::make_unique<SteepFactory>(steepness,enhancedSteepness);
    hollyFactory=std::make_unique<HollyFactory>(steepness,terrainHeal);
}

void CommonFactory::initParams(int health, int enhancedHealth, int armour, float dmgmul, float vampiricMultiplyer,
                               int abPower, int enhancedPower, int abRange, int enhancedAbRange, int mbAgility,
                               int enhancedAgility, int mbRange, int enhancedMbRange, int steepness,
                               int enhancedSteepness, int terrainDamage, int terrainHeal) { this->health=health;
    this->enhancedHealth=enhancedHealth; this->armour=armour; this->dmgmul=dmgmul;
    this->vampiricMultiplyer=vampiricMultiplyer; this->abPower=abPower;
    this->enhancedPower=enhancedPower; this->abRange=abRange;
    this->enhancedAbRange=enhancedAbRange; this->mbAgility=mbAgility;
    this->enhancedAgility=enhancedAgility; this->mbRange=mbRange;
    this->enhancedMbRange=enhancedMbRange;this->steepness=steepness;
    this->enhancedSteepness=enhancedSteepness;
    this->terrainDamage=terrainDamage;this->terrainHeal=terrainHeal;}

std::shared_ptr<GameObject> CommonFactory::createObject(int x, int y, Devotion devotion, CommonClass objectClass) {
    switch (objectClass){

        case CommonClass::NONE:return std::shared_ptr<GameObject>(nullptr);
        case CommonClass::TheRanger:return rangerFactory->createObject(x,y,devotion);
        case CommonClass::ThePowerful:return powerfulFactory->createObject(x,y,devotion);
        case CommonClass::TheAgile:return agileFactory->createObject(x,y,devotion);
        case CommonClass::TheMarathoner:return marathonerFactory->createObject(x,y,devotion);
        case CommonClass::TheTough:return toughFactory->createObject(x,y,devotion);
        case CommonClass::TheVampire:return vampireFactory->createObject(x,y,devotion);
        case CommonClass::SpikyTerrain:return spikyFactory->createObject(x,y,devotion);
        case CommonClass::SteepTerrain:return steepFactory->createObject(x,y,devotion);
        case CommonClass::HollyTerrain:return hollyFactory->createObject(x,y,devotion);
        case CommonClass::Entity1:return std::shared_ptr<GameObject>(nullptr);//TODO entities
        case CommonClass::Entity2:return std::shared_ptr<GameObject>(nullptr);
        case CommonClass::Entity3:return std::shared_ptr<GameObject>(nullptr);
    }
    return std::shared_ptr<GameObject>();
}
