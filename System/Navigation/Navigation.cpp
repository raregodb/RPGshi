#include "Navigation.h"
#include "iostream"


Navigation::Navigation(Player &player, Map &map) : player(player), map(map){
    this->chPos.x=map.getPlayerStart().x;
    this->chPos.y=map.getPlayerStart().y;
    this->deltaMove.x=0;
    this->deltaMove.y=0;
}

void Navigation::initialize(Navigation& navigation) {
    navigation.chPos.x=navigation.map.getPlayerStart().x;
    navigation.chPos.y=navigation.map.getPlayerStart().y;
    navigation.deltaMove.x=0;
    navigation.deltaMove.y=0;
    //navigation.destroyEnemies();
}

void Navigation::chMove(Position pos) {
    Position propPos;
    propPos.x = chPos.x + pos.x;
    propPos.y = chPos.y + pos.y;

    if (player.getInventory()->find(MOUNTAIN_EQUIPMENT)
            && (propPos.x > 0 && propPos.y > 0)
             && (!map.getCellByCords(propPos).getPassability())
             && (propPos.x < map.getMapSizeByX() - 1 && propPos.y < map.getMapSizeByY() - 1)) {
        chPos.x = propPos.x;
        chPos.y = propPos.y;
        player.getInventory()->decItem(MOUNTAIN_EQUIPMENT);
        Cell* some_cell = &map.getCellByCords(chPos);
        if (some_cell->checkForEvent()) {
            some_cell->activateEvent();
        }
    }
    else if (propPos.x < 0 || propPos.y < 0
        || !map.getCellByCords(propPos).getPassability()
        || propPos.x > map.getMapSizeByX() || propPos.y > map.getMapSizeByY()) {
        //std::cout<<"badPosition\n"; //логгирование
    }
    else {
        //std::cout<<"Вы передвинулись с "<<chPos.x<<"; "<<chPos.y<<" на "<<propPos.x<<"; "<<propPos.y<<"\n"; логгирование
        chPos.x = propPos.x;
        chPos.y = propPos.y;
        Cell* some_cell = &map.getCellByCords(chPos);
        if (some_cell->checkForEvent()) {
            some_cell->activateEvent();
        }
    }
}

void Navigation::move(input_commands dir = input_commands()) {
    switch (dir) {
        case Right:
            deltaMove.x = 1;
            deltaMove.y = 0;
            chMove(deltaMove);
            break;
        case Left:
            deltaMove.x = -1;
            deltaMove.y = 0;
            chMove(deltaMove);
            break;
        case Up:
            deltaMove.x = 0;
            deltaMove.y = -1;
            chMove(deltaMove);
            break;
        case Down:
            deltaMove.x = 0;
            deltaMove.y = 1;
            chMove(deltaMove);
            break;
        default:
            deltaMove.x = 0;
            deltaMove.y = 0;
    }
}

Position& Navigation::getChPos() {
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

Map &Navigation::getMap() {
    return map;
}

std::vector<std::shared_ptr<Enemy<WGNavigation, WGInteraction>>>& Navigation::getWGEnemies() {
    return WGenemies;
}

void Navigation::updateEnemy() {
    for (auto & WGenemy : WGenemies) {
        WGenemy->setPlayerKnownPos(chPos);
    }
    for (int i = 0; i < WGenemies.size(); ++i) {
        if (WGenemies.at(i)->getIsDead()) {
            auto it = WGenemies.cbegin() + i;
            WGenemies.erase(it);
        }
    }
    for (auto & SHenemy : SHenemies) {
        SHenemy->setPlayerKnownPos(chPos);
    }
    for (int i = 0; i < SHenemies.size(); ++i) {
        if (SHenemies.at(i)->getIsDead()) {
            auto it = SHenemies.cbegin() + i;
            SHenemies.erase(it);
        }
    }
}


void Navigation::destroyEnemies() {
    WGenemies.clear();
    SHenemies.clear();
}

std::vector<std::shared_ptr<Enemy<SHNavigation, SHInteraction>>> &Navigation::getSHEnemies() {
    return SHenemies;
}
