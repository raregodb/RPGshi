#include "Navigation.h"
#include "iostream"


Navigation::Navigation(Player &player, Map &map) : player(player), map(map){
    this->chPos.x=map.getPlayerStart().x;
    this->chPos.y=map.getPlayerStart().y;
    this->deltaMove.x=0;
    this->deltaMove.y=0;
}

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
        std::cout<<"Вы передвинулись с "<<chPos.x<<"; "<<chPos.y<<" на "<<propPos.x<<"; "<<propPos.y<<"\n";
        chPos.x = propPos.x;
        chPos.y = propPos.y;
        if (chPos.x == map.getPlayerFinish().x && chPos.y == map.getPlayerFinish().y){
            player.setIsFinished(true);
        }
        Cell* some_cell = &map.getCellByCords(chPos);
        if (some_cell->checkForEvent()) {
            some_cell->activateEvent();
            some_cell->setHavingEvent(false);
        }
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
    Position abs_difference;
    if(chPos.x > newChPos.x)
        abs_difference.x = (chPos.x - newChPos.x) * -1;
    else
        abs_difference.x = newChPos.x - chPos.x;

    if(chPos.y > newChPos.y)
        abs_difference.y = (chPos.y - newChPos.y) * -1;
    else
        abs_difference.y = newChPos.y - chPos.y;

    Navigation::chMove(abs_difference);
}

Player& Navigation::getPlayer() {
    return player;
}
