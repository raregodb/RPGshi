#ifndef LAB1_INPUTREADER_H
#define LAB1_INPUTREADER_H

#include "iostream"
#include <fstream>
#include <sstream>
#include "../config/Input_Commands_Dir.h"
#include "curses.h"
#include "InputList/InputList.h"

class InputReader {
public:
    explicit InputReader(const std::string &inputConfig);
    input_commands ReadInput();
    ~InputReader();

private:
    std::unordered_map<char, std::string> keyMap;
    std::ifstream configFile;
    HashTable HT;
};


#endif //LAB1_INPUTREADER_H
