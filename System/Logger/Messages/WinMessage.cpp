#include "WinMessage.h"

WinMessage::WinMessage(Player &pl) : player(pl) {
}

std::string WinMessage::getMessage() {
    return "Игрок прошел уровень. Хар-ки: "
    "ОЗ: " + std::to_string(player.getHealth())
    + " ОП: " + std::to_string(player.getScore())
    + " Урон: " + std::to_string(player.getCharacterDamage())
    + " Броня: " + std::to_string(player.getArmor())
    + " Ур.: " + std::to_string(player.getLevel())
    + " Души: " + std::to_string(player.getSouls());

}
