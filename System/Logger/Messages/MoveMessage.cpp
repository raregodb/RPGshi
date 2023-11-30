#include "MoveMessage.h"

MoveMessage::MoveMessage(char key, std::string comm) {
    this->command = comm;
    this->key = key;

}

std::string MoveMessage::getMessage() {
    return "Была нажата кнопка " + std::to_string(key) + " и выполнена команда " + command;
}
