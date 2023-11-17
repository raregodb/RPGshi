#ifndef LAB1_SHOPMENU_H
#define LAB1_SHOP_H

#define FLASHLIGHT_PRICE 10

#include "../IEvent.h"
#include "../../Navigation/Navigation.h"
#include "../../GameStates/ShopMenu.h"
#include "../../../Entities/Items.h"

class Shop : public IEvent{
public:
    explicit Shop(Navigation& navigation);

    void someEvent() override;
    bool checkIsDesctructible() override;

    Event_Type getType() override;
private:
    Player& player;
    ShopMenu ShopMenu;
};


#endif //LAB1_SHOPMENU_H
