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
    Map map;
    Navigation nav(player1, map);

    return 0;
}
