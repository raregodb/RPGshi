#include "InputReader.h"

InputReader::InputReader(const std::string &inputConfig) {
    configFile.open(inputConfig);

    if (configFile.is_open()) {
        char inputKey;

        std::string command;
        std::string line;

        while (std::getline(configFile, line)) {
            if (!(configFile >> inputKey >> command)) {
                std::cout<<"Error while reading input config file. \n";
                break;
            }
            int count = HT.count_command(command);
            if (HT.getCommand(inputKey).empty() && count < 2) {
                if (isupper(inputKey)) {
                    HT.insert_item(inputKey, command);
                    inputKey = tolower(inputKey);
                    HT.insert_item(inputKey, command);
                }
                else {
                    HT.insert_item(inputKey, command);
                    inputKey = toupper(inputKey);
                    HT.insert_item(inputKey, command);
                }
            }
        }
        HT.insert_item(27, "menu");
    }
    else
        std::cout<<"Input config file was not found. \n";
}

input_commands InputReader::ReadInput() {
    int input;
    input = getch();
    if (HT.find(input)) {
        if (HT.getCommand(input) == "move_forward")
            return Up;
        if (HT.getCommand(input) == "move_left")
            return Left;
        if (HT.getCommand(input) == "move_backward")
            return Down;
        if (HT.getCommand(input) == "move_right")
            return Right;
        if (HT.getCommand(input) == "menu")
            return Escape;
    }

    return Default; // Если команда не найдена
}

InputReader::~InputReader() {
    configFile.close();
}

