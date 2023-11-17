#ifndef LAB1_CELL_H
#define LAB1_CELL_H

#include "iostream"
#include "../Events/IEvent.h"

class Cell{
public:
    explicit Cell(bool passability = true);  //<--- конструктор

    void setPassability(bool newPassability);
    bool getPassability() const;

    void spawnEvent(IEvent* event);
    IEvent* getEvent();
    bool checkForEvent() const;
    void setHavingEvent(bool newState);
    void activateEvent();

    ~Cell();

private:
    bool passability;
    bool hasEvent;
    IEvent* event;
};


#endif //LAB1_CELL_H