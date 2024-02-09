#include "Logger.h"

Logger::Logger(LogType lt, IMessage& message) : message(message) {
    this->logType = lt;
}

void Logger::log() {
    switch (logType) {
        case NoLog:
            break;
        case FileLog:
            logFile.log(message);
            break;
        case ConsoleLog:
            logConsole.log(message);
            break;
        case BothLog:
            logFile.log(message);
            logConsole.log(message);
            break;
    }
}
