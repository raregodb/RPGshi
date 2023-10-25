#ifndef LAB1_IEVENT_H
#define LAB1_IEVENT_H

#define DEFAULT_HEALPOTION_HEAL 20
#define DEFAULT_SPIKE_DAMAGE 50

class IEvent {
public:
    virtual void someEvent() = 0;
    virtual void printSomeEvent() = 0;
    virtual ~IEvent() = default;
};


#endif //LAB1_IEVENT_H
