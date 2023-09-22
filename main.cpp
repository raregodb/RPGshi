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
    Navigation nav(player1);
    Map map(50, 40);
    map.printMap();

    /*
    player1.addHealth(-90);
    std::cout<<player1.getHealth()<<std::endl;
    player1.setCharacterDamage(-2);
    std::cout<<player1.getCharacterDamage()<<std::endl;
    player1.setHealth(2);
    movementCheck(nav.getChPos(), nav);
    nav.move(right);
    nav.move(right);
    movementCheck(nav.getChPos(), nav);
     */
    return 0;
}
