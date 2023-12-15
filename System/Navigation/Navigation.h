#ifndef LAB1_NAVIGATION_H
#define LAB1_NAVIGATION_H

#include "../../Entities/Player/Player.h"
#include "../Map/Map.h"
#include "Position.h"
#include "../config/Input_Commands_Dir.h"
#include "../../Entities/Enemy/Enemy.h"
#include <vector>

class WGInteraction;
class WGNavigation;

class Navigation {
public:
    explicit Navigation(Player& player, Map& map);
    static void initialize(Navigation& navigation);

    Position& getChPos();
    void setChPos(Position newChPos);
    void chMove(Position pos);
    void move(input_commands);
    Map& getMap();

    void updateEnemy();
    std::vector<std::shared_ptr<Enemy<WGNavigation, WGInteraction>>>& getWGEnemies();
    std::vector<std::shared_ptr<Enemy<SHNavigation, SHInteraction>>>& getSHEnemies();
    void destroyEnemies();

    Player& getPlayer();

private:
    std::vector<std::shared_ptr<Enemy<WGNavigation, WGInteraction>>> WGenemies;
    std::vector<std::shared_ptr<Enemy<SHNavigation, SHInteraction>>> SHenemies;
    Map &map;
    Position chPos;
    Position deltaMove;
    Player &player;
};


#endif //LAB1_NAVIGATION_H
