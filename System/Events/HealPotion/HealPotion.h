#ifndef LAB1_HEALPOTION_H
#define LAB1_HEALPOTION_H

#include "../IEvent.h"
#include "../../Navigation/Navigation.h"

class HealPotion : public IEvent{
public:
    explicit HealPotion(Navigation &nav);

    void someEvent() override;
    void printSomeEvent() override;

    int getID() override;
private:
    Player& player;
    int ID;
};


#endif //LAB1_HEALPOTION_H
