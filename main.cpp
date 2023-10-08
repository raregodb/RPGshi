#include <iostream>
#include <string>
#include "Player.h"
#include "Navigation.h"
#include "Map.h"
#include "MapGenerator.h"


int main() {
    Player player1;
    Map map(10, 10);
    Navigation nav(player1, map);
    MapGenerator GMap(map, nav);
    map.printMap();
    nav.move(down);
    nav.move(down);
    nav.move(down);
    nav.move(down);
    nav.move(down);
    nav.move(left);
    nav.move(down);
    nav.move(right);
    nav.move(right);
    nav.move(right);
    nav.move(right);
    nav.move(up);
    nav.move(up);
    nav.move(up);

    return 0;
}
