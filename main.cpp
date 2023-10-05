#include <iostream>
#include <string>
#include "Player.h"
#include "Navigation.h"
#include "Map.h"
#include "IEvent.h"
#include "Spikes.h"
#include "HealPotion.h"
#include "Teleport.h"
#include "MapGenerator.h"

void movementCheck(Navigation nav){
    Position pos = nav.getChPos();
    std::cout<<pos.x<<"; ";
    std::cout<<pos.y<<std::endl;
}


int main() {
    Player player1;
    Map map(10, 10);
    Navigation nav(player1, map);
    MapGenerator GMap(map, nav);
    map.printMap();
    movementCheck(nav);
    nav.move(down);
    movementCheck(nav);
    nav.move(down);
    movementCheck(nav);
    nav.move(down);
    movementCheck(nav);
    nav.move(down);
    movementCheck(nav);
    nav.move(down);
    movementCheck(nav);
    nav.move(left);
    movementCheck(nav);
    nav.move(down);
    movementCheck(nav);
//    nav.move(down);
//    nav.move(down);
//    nav.move(left);
//    Position p1;
//    p1.x = 2;
//    p1.y = 3;
//    Position p2;
//    p2.x = 2;
//    p2.y = 4;
//    if (p1!=p2)
//        std::cout<<"ok"<<std::endl;
//    else
//        std::cout<<"not equal"<<std::endl;

//    std::cout<<player1.getHealth()<<std::endl;
//    Cell start = map.getCellByCords(nav.getChPos());
    movementCheck(nav);
//    Position pos1;
//    pos1.x = 1;
//    pos1.y = 3;
//    Position pos2;
//    pos2.x = 1;
//    pos2.y = 4;
//    Position pos3;
//    pos3.x = 1;
//    pos3.y = 5;
//    Spikes spikes(nav);
//    Spikes* sp = &spikes;
//
//    HealPotion heal(nav);
//    HealPotion* hp = &heal;
//
//    Teleport teleport(nav, map);
//    Teleport* tp = &teleport;
//    map.getCellByCords(pos1).spawnEvent(sp);
//    map.getCellByCords(pos2).spawnEvent(sp);
//    map.getCellByCords(pos3).spawnEvent(sp);
//
//    //map.getCellByCords(pos).getEvent()->someEvent();
//
//
//    nav.move(down);
//    nav.move(down);
//    Cell ch = map.getCellByCords(nav.getChPos());
//    movementCheck(nav);
//    std::cout<<player1.getScore()<<std::endl;
//    std::cout<<player1.getHealth()<<std::endl;
//    nav.move(down);
//    movementCheck(nav);
//    std::cout<<player1.getScore()<<std::endl;
//
//    std::cout<<player1.getHealth()<<std::endl;
//    nav.move(down);
//    movementCheck(nav);
//    std::cout<<player1.getScore()<<std::endl;
//    std::cout<<player1.getHealth()<<std::endl;
//    ch = map.getCellByCords(nav.getChPos());
    return 0;
}
