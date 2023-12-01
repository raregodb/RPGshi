#ifndef LAB1_ILOGGER_H
#define LAB1_ILOGGER_H

#include "../Messages/LoseMessage.h"
#include "../Messages/NewGameMessage.h"
#include "../Messages/WinMessage.h"
#include "../Messages/MoveMessage.h"
#include "../Messages/NoMoveMessage.h"

class ILogger {
public:
    virtual void log(IMessage& message) = 0;
};


#endif //LAB1_ILOGGER_H
