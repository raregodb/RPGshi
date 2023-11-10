#include "RenderGame.h"

RenderGame::RenderGame(Navigation& nNavigation, Player& pPlayer, Map& mMap)
: map(mMap), navigation(nNavigation), player(pPlayer) {
    this->hp = player.getHealth();
    this->score = player.getScore();
    this->damage = player.getCharacterDamage();
    this->lvl = player.getLevel();
}

void RenderGame::printInterface() const {
    std::cout << red << termcolor::bold << "HP: " << hp << "/" << player.getMaxHealth() << " "
    << termcolor::blue << " XP: " << score << violet
    << " Damage: " << damage << termcolor::cyan
    << " Level: " << lvl << treset <<  std::endl;
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
                    std::cout<< termcolor::bold << on_grey << green << "P " << treset;
                }
                else if(map.getCellByCords(pos).checkForEvent() ) {
                    int ID = map.getCellByCords(pos).getEvent()->getID();
                    switch (ID) {
                        case 1:
                            std::cout << green << on_grey <<"♥ ";
                            break;
                        case 2:
                            std::cout << red << on_grey << "ᚈ " << treset;
                            break;
                        case 3:
                            std::cout << termcolor::blue << on_grey << "֍ ";
                            break;
                        case 4:
                            std::cout << green << on_grey << "X ";
                            break;
                        default:
                            std::cout << termcolor::blue << on_grey << "D ";
                            break;
                    }
                }
                else
                    std::cout<< on_grey << termcolor::grey << "  " << treset;

            }
            else if (!map.getCellByCords(pos).getPassability())
                std::cout << termcolor::on_color<240> << termcolor::color<180> << "ᗑ " << treset;
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
    printMap();
    printEvent();
    endwin();
}

void RenderGame::printWin() {
    system("clear");
    printInterface();
    std::cout<<"Вы прошли уровень!\nВы стали гораздо сильнее!\n";
    printMap();
    endwin();
}

