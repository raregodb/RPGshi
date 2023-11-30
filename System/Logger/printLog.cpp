
#include "printLog.h"

printLog::printLog(LogType lt, IMessage& message, bool& firstrun) : message(message), consoleLogger(Logger(&logConsole)),
                                                    fileLogger(Logger(&logFile)), firstRun(firstrun){
    this->logType = lt;
}

void printLog::log() {
    switch (logType) {
        case NoLog:
            break;
        case FileLog:
            fileLogger.send(message, firstRun);
            break;
        case ConsoleLog:
            consoleLogger.send(message, firstRun);
            break;
        case BothLog:
            fileLogger.send(message, firstRun);
            consoleLogger.send(message, firstRun);
            break;
    }
    firstRun = false;
}
