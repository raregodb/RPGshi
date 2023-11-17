#include "Shop.h"

Shop::Shop(Navigation &navigation) : player(navigation.getPlayer()) {
    this->Type = E_SHOP;
    this->isDestructible = false;
}

void Shop::someEvent() {
    bool flag = true;
    while (flag) {
        ShopMenu.open();
        switch (ShopMenu.getChoice()) {
            case 1:
                if (player.takeSouls(FLASHLIGHT_PRICE))
                    player.getInventory()->addItem(TORCH);
                break;
            case 2:
                player.setCharacterDamage(player.getCharacterDamage() + 1);
                break;
            case 3:
                endwin();
                flag = false;
                break;
        }
    }
}

bool Shop::checkIsDesctructible() {
    return isDestructible;
}

Event_Type Shop::getType() {
    return Type;
}
