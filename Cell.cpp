#include "Cell.h"

Cell::Cell(bool passability) : event(nullptr) {
    this->passability = passability;
}

void Cell::setPassability(bool newPassability) {
    passability=newPassability;
}

bool Cell::getPassability() {
    return passability;
}

void Cell::spawnEvent(IEvent *newEvent) {
    event = newEvent;
}

IEvent& Cell::getEvent() const {
    return *event;
}

bool Cell::hasEvent() {
    if (this->event != nullptr)
        return true;
    else
        return false;
}
