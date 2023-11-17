

#include "EventStack.h"

EventStack::EventStack(int _size) {
    m = new Event_Type[_size];

    this->_size = 0;
}

EventStack::~EventStack() {
    delete[] m;
}

void EventStack::push(Event_Type v) {
    m[_size++] = v;
}

int EventStack::pop() {
    return m[--_size];
}

int EventStack::back() {
    return m[_size-1];
}

int EventStack::size() {
    return _size;
}

void EventStack::clear() {
    _size = 0;
}
