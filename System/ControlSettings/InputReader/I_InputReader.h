#ifndef LAB1_I_INPUTREADER_H
#define LAB1_I_INPUTREADER_H

#include "../../config/Input_Commands_Dir.h"
#include "map"

class I_InputReader {
    virtual input_commands read(std::map<int, std::string>* KeyConfig) = 0;
};


#endif //LAB1_I_INPUTREADER_H
