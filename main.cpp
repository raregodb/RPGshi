#include <iostream>
#include <string>
#include "Player.h"
#include "Navigation.h"

void movementCheck(position pos, Navigation nav){
    pos = nav.getChPos();
    std::cout<<pos.x<<"; ";
    std::cout<<pos.y<<std::endl;
}


int main() {
    Player player1;

    Navigation nav(player1);

    std::cout<<player1.getHealth()<<std::endl;
    std::cout<<player1.getCharacterDamage()<<std::endl;
    player1.setHealth(50);
    std::cout<<player1.getHealth()<<std::endl;
    player1.takeDamage(20);
    std::cout<<player1.getHealth()<<std::endl;
    player1.takeDamage(100);
    std::cout<<player1.getHealth()<<std::endl;
    player1.setHealth(-2);
    std::cout<<player1.getNickname()<<std::endl;
    player1.setNickname("TrueKing");
    std::cout<<player1.getNickname()<<std::endl;

    movementCheck(nav.getChPos(), nav);
    nav.move(right);
    movementCheck(nav.getChPos(), nav);
    nav.move(right);
    nav.move(down);
    movementCheck(nav.getChPos(), nav);
    nav.move(up);
    movementCheck(nav.getChPos(), nav);
    nav.move(up);
    movementCheck(nav.getChPos(), nav);

    return 0;
}
