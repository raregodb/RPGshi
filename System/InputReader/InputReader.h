#ifndef LAB1_INPUTREADER_H
#define LAB1_INPUTREADER_H

#include "iostream"
#include <fstream>
#include "../config/Input_Commands_Dir.h"
#include "curses.h"
#include "InputList/InputList.h"

class InputReader {
public:
    explicit InputReader(const std::string &inputConfig);
    input_commands ReadInput();
    ~InputReader();

private:
    std::ifstream configFile;
    InputList HT;
};


#endif //LAB1_INPUTREADER_H
