#include "Teleport.h"

Teleport::Teleport(Navigation& nav, Map& map) : player(nav.getPlayer()), map1(map), navigation1(nav) {
//    int flag = true;
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_int_distribution<> dist(1, map.getMapSizeByX()-2);
//    srand(time(nullptr));
//    while (flag) {
//        Position random_position;
//        //int random_n = dist(gen);
//        int random_n = rand() % (map1.getMapSizeByX()-1) + 1;
//        random_position.x = random_n;
//        //random_n = dist(gen);
//        random_position.y = random_n;
//        if (map1.getCellByCords(random_position).getPassability()) {
//            this->destination = random_position;
//            flag = false;
//        }
//    }
}

void Teleport::someEvent() {
    player.takeDamage(5);
    player.addScore(1);
    srand(player.getScore());
    int flag = true;

//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_int_distribution<> dist(1, map1.getMapSizeByX()-2);
//    std::uniform_int_distribution<> dist2(1, map1.getMapSizeByY()-2);

    while (flag) {
        Position random_position;
        //int random_n = dist(gen);
        int random_n = 1 + rand() % (map1.getMapSizeByX()-1);
        random_position.x = random_n;
        //random_n = dist2(gen);
        random_n = 1 + rand() % (map1.getMapSizeByY()-1);
        random_position.y = random_n;
        if (map1.getCellByCords(random_position).getPassability()) {
            this->destination = random_position;
            flag = false;
        }
    }

    navigation1.setChPos(destination);

    //std::cout<<"\nteleported to " << destination.x << " " << destination.y << std::endl;
}