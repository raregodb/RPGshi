#include "NoMoveMessage.h"

NoMoveMessage::NoMoveMessage(char Kkey) {
    this->key = Kkey;
}

std::string NoMoveMessage::getMessage() {
    return "Недопустимый ввод клавиши (ASCII) " + std::to_string(key);
}
