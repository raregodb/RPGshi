#ifndef LAB1_NAVIGATION_H
#define LAB1_NAVIGATION_H

#include "../../Entities/Player.h"
#include "../Map/Map.h"
#include "Position.h"
#include "../config/Input_Commands_Dir.h"
#include "../Game/Render/EventStack.h"

class Player;

class Navigation {
public:
    explicit Navigation(Player& player, Map& map);
    static void initialize(Navigation& navigation);

    Position getChPos();
    void setChPos(Position newChPos);
    void chMove(Position pos);
    void move(input_commands);

    Player& getPlayer();

private:
    Map &map;
    Position chPos;
    Position deltaMove;
    Player &player;
};


#endif //LAB1_NAVIGATION_H
