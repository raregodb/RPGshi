#ifndef LAB1_NAVIGATION_H
#define LAB1_NAVIGATION_H

#include "Player.h"
#include "Map.h"
#include "Position.h"
#include "IEvent.h"
#define DEFAULT_CELL_DAMAGE 50

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
protected:
    Player &player;
};



#endif //LAB1_NAVIGATION_H
