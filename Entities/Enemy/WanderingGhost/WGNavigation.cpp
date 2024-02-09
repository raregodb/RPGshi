#include "WGNavigation.h"

void WGNavigation::navigate(Position& position, Position& playerPosition, Map& map) {
    bool flag = true;
    while (flag) {
        int random_n = Random::getRandomNumber(1, 4);
        Position tryPosition = position;
        switch (random_n) {
            case 1:
                tryPosition.x++;
                if (map.getCellByCords(tryPosition).getPassability() ) {
                    position.x += 1;
                    flag = false;
                }
                break;
            case 2:
                tryPosition.y++;
                if (map.getCellByCords(tryPosition).getPassability()) {
                    position.y += 1;
                    flag = false;
                }
                break;
            case 3:
                tryPosition.x -= 1;
                if (map.getCellByCords(tryPosition).getPassability()) {
                    position.x -= 1;
                    flag = false;
                }
                break;
            case 4:
                tryPosition.y--;
                if (map.getCellByCords(tryPosition).getPassability()){
                    position.y -= 1;
                    flag = false;
                }
                break;
            default:
                break;
        }
    }
}

