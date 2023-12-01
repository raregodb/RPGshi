#include "LoseMessage.h"

LoseMessage::LoseMessage(Navigation &nav) : navigation(nav){
    this->DeathCell = navigation.getChPos();
}

std::string LoseMessage::getMessage() {
    return  "Игрок проиграл, умерев на координатах " + std::to_string(DeathCell.x) + ' '
              + std::to_string(DeathCell.y) + " на " +
              std::to_string(navigation.getPlayer().getLevel()) + " уровне";
}
