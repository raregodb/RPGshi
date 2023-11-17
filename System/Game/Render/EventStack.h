
#ifndef LAB1_EVENTSTACK_H
#define LAB1_EVENTSTACK_H

#include "../../Events/Event_Types.h"

class EventStack {
public:

    explicit EventStack(int _size);
    ~EventStack();

    void push(Event_Type v);
    int pop();
    int back();
    int size();
    void clear();

private:

    Event_Type* m;

    int _size;
};


#endif //LAB1_EVENTSTACK_H
