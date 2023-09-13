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
    Player pp1;

    Navigation nav(pp1);

    std::cout<<pp1.getHealth()<<std::endl;
    std::cout<<pp1.getCharacterDamage()<<std::endl;
    std::cout<<pp1.getCanBeDamaged()<<std::endl;
    pp1.setHealth(50);
    std::cout<<pp1.getHealth()<<std::endl;
    pp1.takeDamage(20);
    std::cout<<pp1.getHealth()<<std::endl;
    std::cout<<pp1.getCanBeDamaged()<<std::endl;
    pp1.takeDamage(100);
    std::cout<<pp1.getHealth()<<std::endl;
    pp1.setHealth(-2);
    std::cout<<pp1.getIsDead()<<std::endl;
    std::cout<<pp1.getNickname()<<std::endl;
    pp1.setNickname("raregpd");
    std::string nick = pp1.getNickname();
    std::cout<<nick<<std::endl;

    movementCheck(nav.getChPos(), nav);



    return 0;
}
