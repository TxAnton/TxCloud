//
// Created by anton on 5/9/20.
//

#ifndef OOPROJECT_STATS_H
#define OOPROJECT_STATS_H

static const int defaultSteepness = 2;
static const int highSteepness = 7;
static const int defaultRange= 2;
static const int highRange= 5;


enum class Devotion{
    Neuter,
    Light,
    Dark
};

enum class ObjectType{
    Unit,
    Entity,
    Terrain
};

enum class UnitType{
    AbleUnit,
    MobileUnit,
    EnduringUnit
};

enum class CommonClass{
    NONE,
    TheRanger,
    ThePowerful,
    TheAgile,
    TheMarathoner,
    TheTough,
    TheVampire,
    SpikyTerrain,
    SteepTerrain,
    HollyTerrain,
    Entity1,
    Entity2,
    Entity3,

};

enum class TerrainType{
    SpikyTerrain,
    SteepTerrain,
    HollyTerrain
};

struct GameObjectFlyWeight{
    std::string name = "NoName";
    //CommonClass commonClass = CommonClass::NONE;
    char symbol = '@';
};

#endif //OOPROJECT_STATS_H
