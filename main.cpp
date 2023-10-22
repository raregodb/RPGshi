#include <iostream>
#include <string>
#include "Player.h"
#include "Navigation.h"
#include "Map.h"
#include "MapGenerator.h"


int main() {
    Player player1;
    Map map(7, 7);
    Navigation nav(player1, map);
    MapGenerator GMap(map, nav);
    map.printMap();

    while(true) {
        char dir;
        std::cin>>dir;
        switch (dir) {
            case 'a':
                nav.move(left);
                break;
            case 'w':
                nav.move(up);
                break;
            case 'd':
                nav.move(right);
                break;
            case 's':
                nav.move(down);
                break;
        }
    }

    return 0;
}
