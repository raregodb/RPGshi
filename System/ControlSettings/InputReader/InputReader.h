#ifndef LAB1_INPUTREADER_H
#define LAB1_INPUTREADER_H

#include "iostream"

#include "curses.h"
#include "../InputList/InputList.h"
#include "I_InputReader.h"

class InputReader : public I_InputReader {
public:
    input_commands read(std::map<int, std::string>* KeyConfig) override;
};


#endif //LAB1_INPUTREADER_H
