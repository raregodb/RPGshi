#include "LogFile.h"


static std::ostream &operator<<(std::ostream &os, IMessage& _date) {
    return os << _date.getMessage() << std::endl;
}

LogFile::LogFile() : firstRun(true){
}

void LogFile::log(IMessage &message, bool& firstRun) {
    if (firstRun) {
        outputFile.open("../System/config/logFile.txt", std::ios::out);
    }
    else
        outputFile.open("../System/config/logFile.txt", std::ios::app);

    if (outputFile.is_open()) {
        outputFile << message << std::endl;
    }
}

LogFile::~LogFile() {
    if (outputFile.is_open())
        outputFile.close();
}
