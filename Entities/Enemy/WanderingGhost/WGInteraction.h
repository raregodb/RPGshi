#ifndef LAB1_WGINTERACTION_H
#define LAB1_WGINTERACTION_H

#include "../../Player/Player.h"
#include "../Enemy.h"

class Player;

template <class T1, class T2>
class Enemy;

class WGNavigation;

class WGInteraction{
public:
    static void interact(Player& player, Position& playerPosition, Enemy<WGNavigation, WGInteraction>& enemy);
};


#endif //LAB1_WGINTERACTION_H
