#ifndef LAB1_HEALPOTION_H
#define LAB1_HEALPOTION_H

#include "IEvent.h"
#include "Navigation.h"

class HealPotion : public IEvent{
public:
    HealPotion(Navigation &nav);

    void someEvent() override;
private:
    Player& player;
};


#endif //LAB1_HEALPOTION_H
