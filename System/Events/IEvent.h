#ifndef LAB1_IEVENT_H
#define LAB1_IEVENT_H

#define DEFAULT_HEALPOTION_HEAL 20
#define DEFAULT_SPIKE_DAMAGE 50

#include "Event_Types.h"

class IEvent {
public:
    virtual void someEvent() = 0;
    virtual bool checkIsDesctructible() = 0;
    virtual ~IEvent() = default;
    virtual Event_Type getType() = 0;
    Event_Type Type = NONE;
protected:
    bool isDestructible = false;
};


#endif //LAB1_IEVENT_H
