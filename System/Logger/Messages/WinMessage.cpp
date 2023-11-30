#include "WinMessage.h"

WinMessage::WinMessage(Player &pl) : player(pl) {
}

int WinMessage::getHealth() {
    return player.getHealth();
}

int WinMessage::getExperience() {
    return player.getScore();
}

int WinMessage::getDamage() {
    return player.getCharacterDamage();
}

int WinMessage::getArmor() {
    return player.getArmor();
}

int WinMessage::getSouls() {
    return player.getSouls();
}

int WinMessage::getLevel() {
    return player.getLevel();
}

std::string WinMessage::getMessage() {
    return "Игрок прошел уровень. Хар-ки: " + std::to_string(getHealth()) + " "
    + std::to_string(getExperience()) + " "
    + std::to_string(getDamage()) + " "
    + std::to_string(getArmor()) + " "
    + std::to_string(getLevel()) + " "
    + std::to_string(getSouls());

}





