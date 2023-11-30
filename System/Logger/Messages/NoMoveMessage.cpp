#include "NoMoveMessage.h"

NoMoveMessage::NoMoveMessage(char Kkey) {
    this->key = Kkey;
}

std::string NoMoveMessage::getMessage() {
    return "Была нажата клавиша с ASCII кодом " + std::to_string(key) + ", но такой команды нет. ";
}
