#ifndef LAB1_SHOPMENU_H
#define LAB1_SHOP_H

#include "../IEvent.h"
#include "../../Navigation/Navigation.h"
#include "../../GameStates/ShopMenu.h"
#include "../../../Entities/Player/Items.h"

class Shop : public IEvent{
public:
    explicit Shop(Navigation& navigation);

    void someEvent() override;
    bool checkIsDesctructible() override;

    Event_Type getType() override;
private:
    Player& player;
    Navigation& navigation1;
};


#endif //LAB1_SHOPMENU_H
