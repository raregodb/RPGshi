#include "Teleport.h"

Teleport::Teleport(Navigation& nav, Map& map) : player(nav.getPlayer()), map1(map), navigation1(nav) {
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
        if (map1.getCellByCords(random_position).getPassability()) {
            this->destination = random_position;
            flag = false;
        }
    }
    navigation1.setChPos(destination);
}

void Teleport::printSomeEvent() {
    std::cout<<"Волшебный портал перенес вас на " << destination.x << " " << destination.y << "\n\n";
}
