#ifndef LAB1_LOGGER_H
#define LAB1_LOGGER_H

#include "Log/LogType.h"
#include "Log/Log.h"
#include "Log/LogFile.h"

class Logger {
public:
    Logger(LogType lt, IMessage& message);

    void log();

private:
    LogType logType;
    Log logConsole;
    LogFile logFile;
    IMessage& message;
};


#endif //LAB1_LOGGER_H
