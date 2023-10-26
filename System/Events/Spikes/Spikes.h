#ifndef LAB1_SPIKES_H
#define LAB1_SPIKES_H

#include "../IEvent.h"
#include "../../Navigation/Navigation.h"

class Spikes : public IEvent{
public:
    Spikes(Navigation& navigation);

    void someEvent() override;
    void printSomeEvent() override;

    int getID() override;
private:
    Player& player;
    int ID;
};


#endif //LAB1_SPIKES_H
