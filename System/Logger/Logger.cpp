#include "Logger.h"

Logger::Logger(ILogger *observer) : observer(observer) {

}

void Logger::send(IMessage &message, bool& first_run) {
    observer->log(message, first_run);
}
