#include "Teleport.h"

Teleport::Teleport(Navigation& nav, Map& map) : player(nav.getPlayer()), map1(map), navigation1(nav) {
    this->Type = E_TELEPORT;
    this->isDestructible = true;
    this->hasDelayedOutput = true;
}

void Teleport::someEvent() {
    player.takeDamage(5);
    player.addScore(1);
    srand(player.getScore());
    int flag = true;

    while (flag) {
        Position random_position;
        int random_n = 1 + rand() % (map1.getMapSizeByX()-1);
        random_position.x = random_n;
        random_n = 1 + rand() % (map1.getMapSizeByY()-1);
        random_position.y = random_n;
        if (map1.getCellByCords(random_position).getPassability() && random_position != map1.getPlayerFinish()) {
            this->destination = random_position;
            flag = false;
        }
    }
    RenderGame(navigation1, player, map1).printEvent();
    map1.getCellByCords(navigation1.getChPos()).setHavingEvent(false);
    navigation1.setChPos(destination);
}

Event_Type Teleport::getType() {
    return Type;
}

bool Teleport::checkIsDesctructible() {
    return isDestructible;
}
