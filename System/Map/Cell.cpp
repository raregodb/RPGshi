#include "Cell.h"

Cell::Cell(bool passability) : event(nullptr) {
    this->passability = passability;
}

void Cell::setPassability(bool newPassability) {
    passability=newPassability;
}

bool Cell::getPassability() const {
    return passability;
}

void Cell::spawnEvent(IEvent *newEvent) {
    this->event = newEvent;
}

IEvent* Cell::getEvent(){
    return event;
}

bool Cell::checkForEvent() const {
    if (this->hasEvent)
        return true;
    else
        return false;
}

void Cell::activateEvent() {
    this->event->someEvent();
}

void Cell::printEvent() {
    this->event->printSomeEvent();
}

Cell::~Cell() {
    delete event;
}

void Cell::setHavingEvent(bool newState) {
    this->hasEvent = newState;
}
