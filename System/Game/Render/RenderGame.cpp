#include "RenderGame.h"

RenderGame::RenderGame(Navigation& nNavigation, Player& pPlayer, Map& mMap)
: map(mMap), navigation(nNavigation), player(pPlayer) {
    this->hp = player.getHealth();
    this->score = player.getScore();
    this->damage = player.getCharacterDamage();

    //system("clear");
    printInterface();
    printMap();
    printEvent();
}

void RenderGame::printInterface() const {
    std::cout<<"HP: " << hp << " XP: " << score << " Damage: " << damage << std::endl;
}

void RenderGame::printMap() {
    //map.getCellByCords()
    for (int y = 0; y < map.getMapSizeByY(); y++) {
        for (int x = 0; x < map.getMapSizeByX(); x++) {
            Position pos;
            pos.x = x;
            pos.y = y;
            if (map.getCellByCords(pos).getPassability()) {
                if (navigation.getChPos() == pos) {
                    std::cout<<"p";
                }
                else if(map.getCellByCords(pos).checkForEvent() ) {
                    std::cout<<"e";
                }
                else
                    std::cout<<" ";

            }
            else if (!map.getCellByCords(pos).getPassability())
                std::cout<<"#";
        }
        std::cout<<std::endl;
    }

}

void RenderGame::printEvent() {
    Cell* some_cell = &map.getCellByCords(navigation.getChPos());
    if (some_cell->checkForEvent()) {
        some_cell->printEvent();
        some_cell->setHavingEvent(false);
    }

}
