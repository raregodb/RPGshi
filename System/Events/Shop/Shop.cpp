#include "Shop.h"

Shop::Shop(Navigation &navigation) : player(navigation.getPlayer()), navigation1(navigation) {
    this->Type = E_SHOP;
    this->isDestructible = false;

}

void Shop::someEvent() {
    ShopMenu ShopMenu(navigation1);
    bool flag = true;
    while (flag) {
        ShopMenu.open();
        switch (ShopMenu.getChoice()) {
            case 1:
                if (player.takeSouls(TORCH_PRICE) && !player.getInventory()->find(TORCH)) {
                    player.getInventory()->addItem(TORCH);
                    player.setFOV(5);
                }
                else if (player.takeSouls(TORCH_PRICE))
                    player.setFOV(player.getFOV() + 1);
                break;
            case 2:
                if (player.takeSouls(EQUIPMENT_UPGRADE_PRICE)) {
                    player.addCharacterDamage(1);
                    player.addArmor(1);
                }
                break;
            case 3:
                if (player.takeSouls(MOUNTAIN_EQUIPMENT_PRICE)
                && !player.getInventory()->find(MOUNTAIN_EQUIPMENT)) {
                    player.getInventory()->addItem(MOUNTAIN_EQUIPMENT);
                }
                else if (player.takeSouls(MOUNTAIN_EQUIPMENT_PRICE)) {
                    player.getInventory()->incAmountOfItem(MOUNTAIN_EQUIPMENT);
                }
                break;
            case 4:
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
