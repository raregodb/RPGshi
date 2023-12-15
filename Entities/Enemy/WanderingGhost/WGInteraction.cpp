#include "WGInteraction.h"
//template <>
void WGInteraction::interact(Player &player, Position& playerPosition, Enemy<WGNavigation, WGInteraction>& enemy) {

    std::cout<<"interacting..."<<std::endl;
    player.takeDamage(enemy.getDamage());
    enemy.takeDamage(player.getCharacterDamage());

}
