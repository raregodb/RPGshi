#ifndef LAB1_LOGFILE_H
#define LAB1_LOGFILE_H

#include "ILogger.h"
#include <chrono>
#include "fstream"
#include "string"

class LogFile : public ILogger{
public:
    LogFile();

    void log(IMessage& message) override;

    ~LogFile();

private:
    std::ofstream outputFile;
    bool firstRun;
};


#endif //LAB1_LOGFILE_H
