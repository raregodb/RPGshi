#ifndef LAB1_SOULS_H
#define LAB1_SOULS_H

#include "../IEvent.h"
#include "../../Navigation/Navigation.h"
#include "../../Utility/Random.h"

class Souls : public IEvent{
public:
    explicit Souls(Navigation& navigation);

    void someEvent() override;
    bool checkIsDesctructible() override;

    Event_Type getType() override;
private:
    Player& player;
};


#endif //LAB1_SOULS_H
