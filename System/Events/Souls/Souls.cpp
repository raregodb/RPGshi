#include "Souls.h"

Souls::Souls(Navigation &navigation) : player(navigation.getPlayer()) {
    this->Type = E_SOULS;
    this->isDestructible = true;
}

void Souls::someEvent() {
    int randomSouls = Random::getRandomGen(1, 10);

    player.addSouls(randomSouls);
    player.addScore(randomSouls);
}

bool Souls::checkIsDesctructible() {
    return isDestructible;
}

Event_Type Souls::getType() {
    return Type;
}
