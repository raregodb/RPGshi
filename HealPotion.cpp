#include "HealPotion.h"

HealPotion::HealPotion(Navigation& nav) : player(nav.getPlayer()){
}

void HealPotion::someEvent() {
    player.addHealth(50);
    player.addScore(1);
    std::cout<<"norm\n";
}
