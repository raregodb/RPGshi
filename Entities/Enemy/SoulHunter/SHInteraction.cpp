#include "SHInteraction.h"

void SHInteraction::interact(Player &player, Position& playerPosition, Enemy<SHNavigation, SHInteraction>& enemy) {

    player.takeDamage(enemy.getDamage());
    enemy.takeDamage(player.getCharacterDamage());
    player.setSouls(player.getSouls() - 5);

}