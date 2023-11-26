
#ifndef LAB1_ICOMMANDREADER_H
#define LAB1_ICOMMANDREADER_H

#include "../../config/Input_Commands_Dir.h"
#include "string"
#include <fstream>
#include "map"
#include "iostream"

class ICommandReader {
public:
    virtual void InputSettingsReader(const std::string &inputConfig) = 0;

    virtual ~ICommandReader() = default;
};


#endif //LAB1_ICOMMANDREADER_H
