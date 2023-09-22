
#include "Navigation.h"
#include "iostream"

void Navigation::chMove(Position pos) {
    if ((chPos.x + pos.x) < 0 || (chPos.y + pos.y) < 0) { //pos.x > МаксРазмерКарты || pos.y > МаксРазмерКарты
        std::cout<<"badPosition\n";
    }
    else {
        chPos.x += pos.x;
        chPos.y += pos.y;
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