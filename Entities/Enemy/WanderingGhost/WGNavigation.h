#ifndef LAB1_WGNAVIGATION_H
#define LAB1_WGNAVIGATION_H

#include "../../../System/Utility/Random.h"
#include "../../../System/Map/Map.h"
#include "../Enemy.h"
#include "iostream"

template <class T1, class T2>
class Enemy;

class WGNavigation{
public:
    static void navigate(Position&, Position& playerPosition, Map&);

};





#endif //LAB1_WGNAVIGATION_H
