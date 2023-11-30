#ifndef LAB1_LOGFILE_H
#define LAB1_LOGFILE_H

#include "ILogger.h"

class LogFile : public ILogger{
public:
    LogFile();

    void log(IMessage& message, bool& firsrun) override;

    ~LogFile();

private:
    std::ofstream outputFile;
    bool firstRun;
};


#endif //LAB1_LOGFILE_H
