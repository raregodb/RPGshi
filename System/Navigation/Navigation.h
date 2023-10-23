#ifndef LAB1_NAVIGATION_H
#define LAB1_NAVIGATION_H

#include "../../Entities/Player.h"
#include "../Map/Map.h"
#include "Position.h"

enum direction{
    right,
    left,
    up,
    down
};

class Player;

class Navigation {
public:
    explicit Navigation(Player& player, Map& map);

    Position getChPos();
    void setChPos(Position newChPos);
    void chMove(Position pos);
    void move(direction);

    Player& getPlayer();

private:
    Map &map;
    Position chPos;
    Position deltaMove;
    Player &player;
};


#endif //LAB1_NAVIGATION_H
