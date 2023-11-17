#include "RenderGame.h"

RenderGame::RenderGame(Navigation& nNavigation, Player& pPlayer, Map& mMap)
: map(mMap), navigation(nNavigation), player(pPlayer) {
    this->hp = player.getHealth();
    this->score = player.getScore();
    this->damage = player.getCharacterDamage();
    this->lvl = player.getLevel();
    some_cell = &map.getCellByCords(navigation.getChPos());
}

void RenderGame::printInterface() const {
    std::cout << termcolor::bold
    << red << "HP: " << hp
    << "/" << player.getMaxHealth()
    << blue << " XP: " << score
    << violet << " Damage: " << damage
    << cyan << " Level: " << lvl
    << treset <<  std::endl;
}

void RenderGame::printMap() {
    for (int y = 0; y < map.getMapSizeByY(); y++) {
        for (int x = 0; x < map.getMapSizeByX(); x++) {
            Position pos;
            pos.x = x;
            pos.y = y;
            if (map.getCellByCords(pos).getPassability()) {
                if (navigation.getChPos() == pos) {
                    std::cout << termcolor::bold << on_grey << green << "P " << treset;
                }
                else if(map.getCellByCords(pos).checkForEvent() ) {
                    Event_Type TYPE = map.getCellByCords(pos).getEvent()->getType();
                    switch (TYPE) {
                        case E_HEAL:
                            std::cout << on_grey << red <<"♥ " << treset;
                            break;
                        case E_SPIKES:
                            std::cout << on_grey << termcolor::magenta << "ᚈ " << treset;
                            break;
                        case E_TELEPORT:
                            std::cout << on_grey << blue << "֍ " << treset;
                            break;
                        case E_EXIT:
                            std::cout << on_grey << green << "X " << treset;
                            break;
                        default:
                            std::cout << on_grey << blue << "Er" << treset;
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
    if (some_cell->checkForEvent()) {
        printEvent(some_cell->getEvent()->getType());
    }
}


void RenderGame::printEvent(Event_Type TYPE) {
    switch (TYPE) {
        case E_TELEPORT:
            std::cout << termcolor::bold
                      << "Волшебный портал перенес вас прямиком сквозь астральный план\n" << treset;
            break;
        case E_SPIKES:
            std::cout << termcolor::bold
                      << "Шипы. Было неприятно. Вы получили " << DEFAULT_SPIKE_DAMAGE << " урона. \n" << treset;
            break;
        case E_HEAL:
            std::cout << termcolor::bold
                      << "Отлично! Ты нашел лечебное зелье и восстановил " << DEFAULT_HEALPOTION_HEAL << " ОЗ\n" << treset;
            break;
        case E_EXIT:
            std::cout << termcolor::bold << red
                      << "Вы прошли уровень!\nВы стали гораздо сильнее!\n";
            break;
        case NONE:
            break;
    }
}


void RenderGame::printGame() {
    system("clear");
    printInterface();
    printMap();
    if (some_cell->checkForEvent()) {
        printEvent();
        if (some_cell->getEvent()->checkIsDesctructible())
            some_cell->setHavingEvent(false);
    }
    endwin();
}

void RenderGame::printWin() {
    system("clear");
    printInterface();
    printEvent(E_EXIT);
    printMap();
    endwin();
}
