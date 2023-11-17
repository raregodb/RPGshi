#include "Exit_event.h"

Exit_event::Exit_event(Navigation &nav) : player(nav.getPlayer()) {
    this->Type = E_EXIT;
    this->isDestructible = false;
}

void Exit_event::someEvent() {
    player.setIsFinished(true);
    player.addScore(20);
    player.setMaxHealth(player.getScore() * 5);
    player.setLevel(player.getLevel() + 1);
}

Event_Type Exit_event::getType() {
    return Type;
}

bool Exit_event::checkIsDesctructible() {
    return isDestructible;
}
