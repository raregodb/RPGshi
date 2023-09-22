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

struct Position {
    int x, y;
    Position() {
        this->x=0;
        this->y=0;
    }
};

class Navigation {
public:
    explicit Navigation(Player& player) : player(player){
        this->chPos.x=0;
        this->chPos.y=0;
        this->deltaMove.x=0;
        this->deltaMove.y=0;
    }

    Position getChPos();
    void setChPos(Position newChPos);
    void chMove(Position pos);
    void move(direction);

private:
    Player &player;
    Position chPos;
    Position deltaMove;
};

#endif //LAB1_NAVIGATION_H
