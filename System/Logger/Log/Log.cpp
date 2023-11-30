#include "Log.h"

static std::ostream &operator<<(std::ostream &os, IMessage& _date) {
    return os << _date.getMessage() << std::endl;
}

void Log::log(IMessage& message, bool& firstrun) {
    output<<message;
}

Log::Log() : output(std::cout){
}




