#ifndef LAB1_NAVIGATION_H
#define LAB1_NAVIGATION_H

#include "Player.h"

enum direction{
    right,
    left,
    up,
    down
};

class Player;

struct position {
    int x, y;
    position() {
        this->x=0;
        this->y=0;
    }
};

class Navigation {
public:
    Navigation(Player& player) : player(player){
        this->chPos.x=0;
        this->chPos.y=0;
        this->deltaMove.x=0;
        this->deltaMove.y=0;
    }

    position getChPos();
    void setChPos(position newChPos);
    void chMove(position pos);
    void move(direction);

private:
    Player &player;
    position chPos;
    position deltaMove;
};

#endif //LAB1_NAVIGATION_H
