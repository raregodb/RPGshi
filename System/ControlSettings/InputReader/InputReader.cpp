#include "InputReader.h"

input_commands InputReader::read(std::map<int, std::string>* KeyConfig) {
    int input;
    input = getch();
    if (!KeyConfig->find(input)->second.empty()) {
        if (KeyConfig->find(input)->second == "move_forward")
            return Up;
        if (KeyConfig->find(input)->second == "move_left")
            return Left;
        if (KeyConfig->find(input)->second == "move_backward")
            return Down;
        if (KeyConfig->find(input)->second == "move_right")
            return Right;
        if (KeyConfig->find(input)->second == "menu")
            return Escape;
    }

    return Default; // Если команда не найдена
}
