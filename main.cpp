#include <iostream>
#include <string>
#include "Player.h"
#include "Navigation.h"
#include "Map.h"

void movementCheck(Position pos, Navigation nav){
    pos = nav.getChPos();
    std::cout<<pos.x<<"; ";
    std::cout<<pos.y<<std::endl;
}


int main() {
    Player player1;
    Map map(-4, 120);
    Navigation nav(player1, map);

    Map map2;
    map2 = std::move(map);


    Position pos;

    pos.x = 3;
    pos.y = 3;

    Cell cell1 = map2.getCellByCords(pos);

    return 0;
}
