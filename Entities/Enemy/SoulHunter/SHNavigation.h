#ifndef LAB1_SHNAVIGATION_H
#define LAB1_SHNAVIGATION_H

#include "../Enemy.h"
#include "../../../System/Utility/A*/Pathfinder.h"

class SHNavigation {
public:
    static void navigate(Position&, Position& playerPosition, Map&);

};

#endif //LAB1_SHNAVIGATION_H
