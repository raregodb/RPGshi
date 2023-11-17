#ifndef LAB1_HEALPOTION_H
#define LAB1_HEALPOTION_H

#include "../IEvent.h"
#include "../../Navigation/Navigation.h"

class HealPotion : public IEvent{
public:
    explicit HealPotion(Navigation &nav);

    void someEvent() override;
    bool checkIsDesctructible() override;

    Event_Type getType() override;
private:
    Player& player;
};


#endif //LAB1_HEALPOTION_H
