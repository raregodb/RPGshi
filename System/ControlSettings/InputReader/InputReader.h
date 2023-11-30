#ifndef LAB1_INPUTREADER_H
#define LAB1_INPUTREADER_H

#include "iostream"

#include "curses.h"
#include "I_InputReader.h"
#include "../../Logger/Log/Log.h"
#include "../../Logger/printLog.h"

class InputReader : public I_InputReader {
public:
    input_commands read(std::map<int, std::string>* KeyConfig) override;

    int getInput();

private:
    int input;
};


#endif //LAB1_INPUTREADER_H
