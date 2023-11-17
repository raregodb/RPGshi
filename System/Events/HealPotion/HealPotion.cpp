#include "HealPotion.h"

HealPotion::HealPotion(Navigation& nav) : player(nav.getPlayer()){
    this->Type = E_HEAL;
    this->isDestructible = true;
}

void HealPotion::someEvent() {
    player.addHealth(DEFAULT_HEALPOTION_HEAL);
    player.addScore(1);
}

Event_Type HealPotion::getType() {
    return Type;
}

bool HealPotion::checkIsDesctructible() {
    return isDestructible;
}
