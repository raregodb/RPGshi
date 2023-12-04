#ifndef LAB1_LOG_H
#define LAB1_LOG_H

#include "ILogger.h"

class Log : public ILogger{
public:
    Log();

    void log(IMessage&) override;

private:
    std::ostream& output;
};


#endif //LAB1_LOG_H
