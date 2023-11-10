#ifndef LAB1_EXIT_EVENT_H
#define LAB1_EXIT_EVENT_H

#include "../IEvent.h"
#include "../../Navigation/Navigation.h"

class Exit_event : public IEvent {
public:
    explicit Exit_event(Navigation &nav);

    void someEvent() override;
    void printSomeEvent() override;

    int getID() override;
private:
    Player& player;
};


#endif //LAB1_EXIT_EVENT_H
