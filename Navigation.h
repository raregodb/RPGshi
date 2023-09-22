#ifndef LAB1_NAVIGATION_H
#define LAB1_NAVIGATION_H

#include "Player.h"
#include "Map.h"
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
    explicit Navigation(Player& player, Map& map) : player(player), map(map){
        this->chPos.x=map.getPlayerStart().x;
        this->chPos.y=map.getPlayerStart().y;
        this->deltaMove.x=0;
        this->deltaMove.y=0;
    }

    Position getChPos();
    void setChPos(Position newChPos);
    void chMove(Position pos);
    void move(direction);

private:
    Player &player;
    Map &map;
    Position chPos;
    Position deltaMove;
};

#endif //LAB1_NAVIGATION_H
