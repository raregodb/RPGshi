#ifndef LAB1_LOGFILE_H
#define LAB1_LOGFILE_H

#include "ILogger.h"
#include <chrono>
#include "fstream"
#include "string"

#define DEFAULT_LOG_TIME true

class LogFile : public ILogger{
public:
    LogFile();

    void log(IMessage& message) override;

    ~LogFile();

private:
    std::ofstream outputFile;
    bool firstRun;
    bool TIME;
};


#endif //LAB1_LOGFILE_H
