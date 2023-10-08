#include "HealPotion.h"

HealPotion::HealPotion(Navigation& nav) : player(nav.getPlayer()){

}

void HealPotion::someEvent() {
    player.addHealth(DEFAULT_HEALPOTION_HEAL);
    player.addScore(1);
    std::cout << "Отлично! Ты нашел лечебное зелье и восстановил " << DEFAULT_HEALPOTION_HEAL << " ОЗ\n\n";
}
