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
                if (player.canAfford(TORCH_PRICE) && !(player.getInventory()->find(TORCH))) {
                    player.takeSouls(TORCH_PRICE);
                    player.getInventory()->addItem(TORCH);
                    player.setFOV(5);
                }
                else if (player.canAfford(TORCH_UPGRADE_PRICE) && (player.getInventory()->find(TORCH))) {
                    player.takeSouls(TORCH_UPGRADE_PRICE);
                    player.setFOV(player.getFOV() + 1);
                }
                break;
            case 2:
                if (player.canAfford(EQUIPMENT_UPGRADE_PRICE)) {
                    player.takeSouls(EQUIPMENT_UPGRADE_PRICE);
                    player.addCharacterDamage(5);
                    player.addArmor(5);
                }
                break;
            case 3:
                if (player.canAfford(MOUNTAIN_EQUIPMENT_PRICE)
                && !player.getInventory()->find(MOUNTAIN_EQUIPMENT)) {
                    player.takeSouls(MOUNTAIN_EQUIPMENT_PRICE);
                    player.getInventory()->addItem(MOUNTAIN_EQUIPMENT);
                }

                else if (player.canAfford(MOUNTAIN_EQUIPMENT_PRICE)) {
                    player.takeSouls(MOUNTAIN_EQUIPMENT_PRICE);
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
