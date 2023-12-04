#include "LogFile.h"


static std::ostream &operator<<(std::ostream &os, IMessage& _date) {
    return os << _date.getMessage() << std::endl;
}

LogFile::LogFile(){
    this->firstRun = false;
    this->TIME = DEFAULT_LOG_TIME;
    std::ifstream file("../System/config/logFile.txt");
    std::string line;

    while(std::getline(file, line)) {
        if (line.find("SHUTDOWN") != std::string::npos) {
            this->firstRun = true;
            break;
        }
        else
            this->firstRun = false;
    }
}

void LogFile::log(IMessage &message) {
    auto now = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(now);

    if (!firstRun) {
        outputFile.open("../System/config/logFile.txt", std::ios::app); // ../System/config/logFile.txt
        if (TIME)
            outputFile << "UPD AT " << std::ctime(&end_time);
    }
    else {
        outputFile.open("../System/config/logFile.txt", std::ios::out); // ../System/config/logFile.txt
        outputFile << "LOGGER ver. 1" << std::endl;
    }

    if (outputFile.is_open()) {
        outputFile << message << std::endl;
    }
    else
        std::cout << "Ошибка при вводе в Лог файл" << std::endl;
}

LogFile::~LogFile() {
    if (outputFile.is_open())
        outputFile.close();
}
