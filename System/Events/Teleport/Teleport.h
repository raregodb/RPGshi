#ifndef LAB1_TELEPORT_H
#define LAB1_TELEPORT_H

#include "../IEvent.h"
#include "../../Navigation/Navigation.h"
#include<cstdlib>
#include<ctime>
#include "iostream"
#include <random>

class Teleport : public IEvent{
public:
    Teleport(Navigation& navigation, Map& map);

    void someEvent() override;
    void printSomeEvent() override;

    int getID() override;
private:
    Player& player;
    Map& map1;
    Navigation& navigation1;
    Position destination;

    int ID;
};


#endif //LAB1_TELEPORT_H
