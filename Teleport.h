#ifndef LAB1_TELEPORT_H
#define LAB1_TELEPORT_H

#include "IEvent.h"
#include "Navigation.h"
#include<cstdlib>
#include<ctime>
#include "iostream"
#include <random>

class Teleport : public IEvent{
public:
    Teleport(Navigation& navigation, Map& map);

    void someEvent() override;
private:
    Player& player;
    Map& map1;
    Navigation& navigation1;
    Position destination;
};


#endif //LAB1_TELEPORT_H
