#include "RenderGame.h"

RenderGame::RenderGame(Navigation& nNavigation, Player& pPlayer, Map& mMap)
: map(mMap), navigation(nNavigation), player(pPlayer) {
    this->hp = player.getHealth();
    this->score = player.getScore();
    this->damage = player.getCharacterDamage();

//    system("clear");
//    printInterface();
//    printEvent();
//    printMap();
}

void RenderGame::printInterface() const {
    std::cout << red << termcolor::bold << "HP: " << hp << yellow << " XP: " << score << violet << " Damage: " << damage << treset <<  std::endl;
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
                    std::cout<< termcolor::bold << on_grey << green << termcolor::blink << "P" << treset;
                }
                else if(map.getCellByCords(pos).checkForEvent() ) {
                    int ID = map.getCellByCords(pos).getEvent()->getID();
                    switch (ID) {
                        case 1:
                            std::cout << green << on_grey <<"♥";
                            break;
                        case 2:
                            std::cout << red << on_grey << "ᚈ" << treset; //"෴"
                            break;
                        case 3:
                            std::cout << termcolor::blue << on_grey << "֍";  //൭
                            break;
                    }
                }
                else
                    std::cout<< on_grey << termcolor::grey << " " << treset; //

            }
            else if (!map.getCellByCords(pos).getPassability())
                std::cout << termcolor::on_color<240> << termcolor::color<180> << "ᗑ" << treset;
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

void RenderGame::printGame() {
    system("clear");
    printInterface();
    printEvent();
    printMap();
}

void RenderGame::printMainMenu() {
    std::cout<<"LOL\n";
}