
#ifndef LAB1_PRINTLOG_H
#define LAB1_PRINTLOG_H

#include "Log/ILogger.h"
#include "Log/LogType.h"
#include "Log/Log.h"
#include "Log/LogFile.h"
#include "Logger.h"
#include "Messages/MoveMessage.h"
#include "Messages/NoMoveMessage.h"
#include "Messages/WinMessage.h"
#include "Messages/LoseMessage.h"

class printLog {
public:
    printLog(LogType lt, IMessage& message, bool& firstRun);

    void log();

private:
    LogType logType;
    Log logConsole;
    LogFile logFile;
    IMessage& message;
    Logger consoleLogger;
    Logger fileLogger;
    bool& firstRun;

};


#endif //LAB1_PRINTLOG_H
