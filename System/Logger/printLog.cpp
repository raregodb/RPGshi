
#include "printLog.h"

printLog::printLog(LogType lt, IMessage& message) : message(message),
consoleLogger(Logger(&logConsole)), fileLogger(Logger(&logFile)) {
    this->logType = lt;
}

void printLog::log() {
    switch (logType) {
        case NoLog:
            break;
        case FileLog:
            fileLogger.send(message);
            break;
        case ConsoleLog:
            consoleLogger.send(message);
            break;
        case BothLog:
            fileLogger.send(message);
            consoleLogger.send(message);
            break;
    }
}
