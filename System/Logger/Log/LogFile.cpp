#include "LogFile.h"


static std::ostream &operator<<(std::ostream &os, IMessage& _date) {
    return os << _date.getMessage() << std::endl;
}

LogFile::LogFile() : firstRun(true){
    //outputFile = std::ofstream ("LogFile.txt");
//    if (!needClean) {
//        this->outputFile.open("LogFile.txt", std::ios::app);
//    }
//    else {
//        this->outputFile.open("LogFile.txt", std::ios::out);
//        needClean = false;
//    }
}

void LogFile::log(IMessage &message, bool& firstRun) {
    if (firstRun) {
        outputFile.open("../../config/logFile.txt", std::ios::out);
    }
    else
        outputFile.open("../../config/logFile.txt", std::ios::app);

    if (outputFile.is_open()) {
        outputFile << message << std::endl;
        //outputFile.close();
    }
}

LogFile::~LogFile() {
    if (outputFile.is_open())
        outputFile.close();
}
