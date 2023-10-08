#ifndef LAB1_MAPGENERATOR_H
#define LAB1_MAPGENERATOR_H

#include "Spikes.h"
#include "Teleport.h"
#include "HealPotion.h"
#include "iostream"
#include<cstdlib>
#include<ctime>
#include <random>


class MapGenerator {
public:
    explicit MapGenerator(Map &map, Navigation &navigation);

    void GenerateWalls();
    void RandomGeneration();
    bool isPath();

private:
    Map &map1;
    Navigation & nav;
};


#endif //LAB1_MAPGENERATOR_H
