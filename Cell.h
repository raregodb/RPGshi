#ifndef LAB1_CELL_H
#define LAB1_CELL_H

#include "iostream"
#include "IEvent.h"

class Cell{
public:
    explicit Cell(bool passability = true);  //<--- конструктор

    void setPassability(bool newPassability);
    bool getPassability();

    void spawnEvent(IEvent* event);
    IEvent& getEvent() const;
    bool hasEvent();

private:
    bool passability;
    IEvent* event;
};


#endif //LAB1_CELL_H