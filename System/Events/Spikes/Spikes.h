#ifndef LAB1_SPIKES_H
#define LAB1_SPIKES_H

#include "../IEvent.h"
#include "../../Navigation/Navigation.h"

class Spikes : public IEvent{
public:
    Spikes(Navigation& navigation);

    void someEvent() override;
    void printSomeEvent() override;
private:
    Player& player;
};


#endif //LAB1_SPIKES_H
