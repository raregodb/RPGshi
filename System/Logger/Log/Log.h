#ifndef LAB1_LOG_H
#define LAB1_LOG_H

#include "ILogger.h"

class Log : public ILogger{
public:
    //explicit Log(std::ostream& stream);
    Log();

    void log(IMessage&, bool& firstrun) override;

private:
    std::ostream& output;
    //std::ofstream outputfile;
};


#endif //LAB1_LOG_H
