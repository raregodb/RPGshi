#include "Logger.h"

Logger::Logger(ILogger *observer) : observer(observer) {

}

void Logger::send(IMessage &message) {
    observer->log(message);
}
