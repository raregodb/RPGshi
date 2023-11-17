#ifndef LAB1_SPIKES_H
#define LAB1_SPIKES_H

#include "../IEvent.h"
#include "../../Navigation/Navigation.h"

class Spikes : public IEvent{
public:
    Spikes(Navigation& navigation);

    void someEvent() override;
    bool checkIsDesctructible() override;

    Event_Type getType() override;
private:
    Player& player;
};


#endif //LAB1_SPIKES_H
