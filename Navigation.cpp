
#include "Navigation.h"
#include "iostream"

void Navigation::chMove(Position pos) {
    Position propPos;
    propPos.x = chPos.x + pos.x;
    propPos.y = chPos.y + pos.y;
    if (propPos.x < 0 || propPos.y < 0
        || !map.getCellByCords(propPos).getPassability()
        || propPos.x > map.getMapSizeByX() || propPos.y > map.getMapSizeByY()) {
        std::cout<<"badPosition\n";
    }
    else {
        chPos.x = propPos.x;
        chPos.y = propPos.y;
    }
}


void Navigation::move(direction dir = direction()) {
    switch (dir) {
        case right:
            deltaMove.x = 1;
            deltaMove.y = 0;
            chMove(deltaMove);
            break;
        case left:
            deltaMove.x = -1;
            deltaMove.y = 0;
            chMove(deltaMove);
            break;
        case up:
            deltaMove.x = 0;
            deltaMove.y = -1;
            chMove(deltaMove);
            break;
        case down:
            deltaMove.x = 0;
            deltaMove.y = 1;
            chMove(deltaMove);
            break;
        default:
            deltaMove.x = 0;
            deltaMove.y = 0;
    }
}

Position Navigation::getChPos() {
    return chPos;
}

void Navigation::setChPos(Position newChPos) {
    if (newChPos.x < 0 || newChPos.y < 0) { //newChPos.x > МаксРазмерКарты || newChPos.y > МаксРазмерКарты
        std::cout<<"badPosition\n";
    }
    else {
        chPos.x=newChPos.x;
        chPos.y=newChPos.y;
    }
}