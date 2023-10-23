#include <iostream>
#include <string>
#include "Entities/Player.h"
#include "System/Navigation/Navigation.h"
#include "System/Map/Map.h"
#include "System/Map/MapGenerator/MapGenerator.h"
#include <cstdlib>



bool isDeadOrWin(Player player) {
    if (player.getIsDead()) {
        std::cout<<"Вы умерли :( \nИгра окончена\n";
        return true;
    }
    if (player.getIsFinished()) {
        std::cout<<"Вы прошли уровень!\n";
        return true;
    }
    return false;
}

int main() {
    Player player1;
    Map map(7, 7);
    Navigation nav(player1, map);
    MapGenerator GMap(map, nav);
    map.printMap(nav.getChPos());

    bool end = true;
    while(!isDeadOrWin(player1)) {
        char dir;
        std::cin>>dir;
        switch (dir) {
            case 'a':
                system("clear");
                nav.move(left);
                map.printMap(nav.getChPos());
                break;
            case 'w':
                system("clear");
                nav.move(up);
                map.printMap(nav.getChPos());
                break;
            case 'd':
                system("clear");
                nav.move(right);
                map.printMap(nav.getChPos());
                break;
            case 's':
                system("clear");
                nav.move(down);
                map.printMap(nav.getChPos());
                break;
            default:
                std::cout<<"bad input. use WASD\n";
                break;
        }
    }
    return 0;
}
