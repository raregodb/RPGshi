#include "WGInteraction.h"

void WGInteraction::interact(Player &player, Position& playerPosition, Enemy<WGNavigation, WGInteraction>& enemy) {

    std::cout<<"interacting..."<<std::endl;
    player.takeDamage(enemy.getDamage());
    enemy.takeDamage(player.getCharacterDamage());
    srand(player.getScore());
    int flag = true;
    Position destination;

    while (flag) {
        Position random_position;
        int random_n = 1 + rand() % (enemy.getMap().getMapSizeByX()-1);
        random_position.x = random_n;
        random_n = 1 + rand() % (enemy.getMap().getMapSizeByY()-1);
        random_position.y = random_n;
        if (enemy.getMap().getCellByCords(random_position).getPassability() && random_position != enemy.getMap().getPlayerFinish()) {
            destination = random_position;
            flag = false;
        }
    }
   playerPosition = destination;

}
