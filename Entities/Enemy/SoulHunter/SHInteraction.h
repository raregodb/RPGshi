#ifndef LAB1_SHINTERACTION_H
#define LAB1_SHINTERACTION_H

#include "../../Player/Player.h"
#include "../Enemy.h"

class Player;

template <class T1, class T2>
class Enemy;

class SHNavigation;

class SHInteraction {
public:
    static void interact(Player& player, Position& playerPosition, Enemy<SHNavigation, SHInteraction>& enemy);
};


#endif //LAB1_SHINTERACTION_H
