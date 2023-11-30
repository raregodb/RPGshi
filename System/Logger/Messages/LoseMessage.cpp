#include "LoseMessage.h"

LoseMessage::LoseMessage(Navigation &nav, Player& pPlayer) : navigation(nav), player(pPlayer){
    this->DeathCell = navigation.getChPos();
}

Navigation &LoseMessage::getNavigation() {
    return navigation;
}

Position LoseMessage::getDeathCell() {
    return DeathCell;
}

std::string LoseMessage::getMessage() {
    return  "Игрок проиграл, умерев на координатах " + std::to_string(DeathCell.x) + ' '
              + std::to_string(DeathCell.y) + " на " +
              std::to_string(navigation.getPlayer().getLevel()) + " уровне";
}
