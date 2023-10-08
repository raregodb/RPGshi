#ifndef LAB1_SPIKES_H
#define LAB1_SPIKES_H

#include "IEvent.h"
#include "Navigation.h"

class Spikes : public IEvent{
public:
    Spikes(Navigation& navigation);

    void someEvent() override;
private:
    Player& player;
};


#endif //LAB1_SPIKES_H
