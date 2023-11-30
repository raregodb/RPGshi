
#ifndef LAB1_LOGGER_H
#define LAB1_LOGGER_H

#include "Log/ILogger.h"


class Logger {
public:
    explicit Logger(ILogger* observer);

    void send(IMessage& message, bool& firstrun);

private:
    ILogger* observer;
};


#endif //LAB1_LOGGER_H
