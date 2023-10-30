#include "InputReader.h"

InputReader::InputReader(const std::string &inputConfig) {
    configFile.open(inputConfig);

    if (configFile.is_open()) {
        int inputKey;
        std::string command;
        std::string line;

        while (std::getline(configFile, line)) {
            std::istringstream iss(line);
            if (!(configFile >> inputKey >> command)) {
                std::cout<<"Error while reading input config file. \n";
                break;
            }
            keyMap[inputKey] = command;
        }
    }
    else
        std::cout<<"Input config file was not found. \n";
}

input_commands InputReader::ReadInput() {
    int input;
    input = getch();

    if (keyMap.find(input) != keyMap.end()) {
        //return keyMap[input];
        if (keyMap[input] == "move_forward")
            return Up;
        if (keyMap[input] == "move_left")
            return Left;
        if (keyMap[input] == "move_backward")
            return Down;
        if (keyMap[input] == "move_right")
            return Right;
        if (keyMap[input] == "menu")
            return Escape;
    }
    return Default; // Если команда не найдена
}

InputReader::~InputReader() {
    configFile.close();
}

