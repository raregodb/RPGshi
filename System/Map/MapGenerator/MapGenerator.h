#ifndef LAB1_MAPGENERATOR_H
#define LAB1_MAPGENERATOR_H

#include "../../Events/Spikes/Spikes.h"
#include "../../Events/Teleport/Teleport.h"
#include "../../Events/HealPotion/HealPotion.h"
#include "../../Events/Exit/Exit_event.h"
#include "../../Events/Shop/Shop.h"
#include "../../Events/Souls/Souls.h"
#include "iostream"
#include "../../Utility/Random.h"
#include "vector"
#include "../../../Entities/Enemy/Enemy.h"



class MapGenerator {
public:
    explicit MapGenerator(Map &map, Navigation &navigation);

    void GenerateWalls();
    void RandomGeneration();
    bool isPath();
    void spawnEnemies();

private:
    Map &map1;
    Navigation &nav;


    int maxEnemeis;
    int countEnemies;
    int percentageEnemy;
    int maxTeleports;
    int maxSouls;
    int countTeleports;
    int countSouls;

    int percentageHeal;
    int percentageSpike;
    int percentageTeleport;
    int percentageSouls;

};


#endif //LAB1_MAPGENERATOR_H
