#ifndef LAB1_CELL_H
#define LAB1_CELL_H

#include "iostream"
#include "IEvent.h"

class Cell{
public:
    explicit Cell(bool passability = true);  //<--- конструктор

    void setPassability(bool newPassability);
    bool getPassability() const;

    void spawnEvent(IEvent* event);
    IEvent& getEvent();
    bool hasEvent();
    void activateEvent();

private:
    bool passability;
    IEvent* event;
};


#endif //LAB1_CELL_H