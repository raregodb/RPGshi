#include "RenderGame.h"

RenderGame::RenderGame(Navigation& nNavigation, Player& pPlayer, Map& mMap, bool& fog)
: map(mMap), navigation(nNavigation), player(pPlayer), isFog(fog) {
    this->hp = player.getHealth();
    this->score = player.getScore();
    this->damage = player.getCharacterDamage();
    this->lvl = player.getLevel();
    this->souls = player.getSouls();
    this->armor = player.getArmor();
    if (isFog == true && player.getLevel() >= 10)
        isFog = true;
    else
        isFog = false;
    some_cell = &map.getCellByCords(navigation.getChPos());
}

void RenderGame::printInterface() const {
    std::cout << termcolor::bold
    << red << "ОЗ: " << hp
    << "/" << player.getMaxHealth()
    << blue << " ОП: " << score
    << violet << " Урон: " << damage
    << violet << " Броня: " << armor;
    if (player.getInventory()->find(MOUNTAIN_EQUIPMENT))
        std::cout << violet << " Гор. снар.: " << player.getInventory()->countItem(MOUNTAIN_EQUIPMENT);
    std::cout << cyan << " Уровень: " << lvl
    << termcolor::bright_cyan << " Души: " << souls
    << treset <<  std::endl;
}

void RenderGame::printMap() {
    for (int y = 0; y < map.getMapSizeByY(); y++) {
        for (int x = 0; x < map.getMapSizeByX(); x++) {
            Position pos;
            pos.x = x;
            pos.y = y;

            Position distanceBetweenPandCell;
            distanceBetweenPandCell.x = abs(pos.x - navigation.getChPos().x);
            distanceBetweenPandCell.y = abs(pos.y - navigation.getChPos().y);


            if (navigation.getChPos() == pos && !some_cell->getPassability()) {
                std::cout << termcolor::bold << termcolor::on_color<240> << green << "P " << treset; //P 👤
            }
            else if (navigation.getChPos() == pos) {
                std::cout << termcolor::bold << on_grey << green << "P " << treset; //P 👤
            }
            else if(isFog && (distanceBetweenPandCell.x >= navigation.getPlayer().getFOV() || distanceBetweenPandCell.y >= navigation.getPlayer().getFOV())) {
                int random_n = Random::getRandomGen(1, 10);

                if (random_n <= 3)
                    std::cout << termcolor::bold << termcolor::on_color<237> << termcolor::color<245> <<"☁ " << treset;
                else if (random_n <= 6)
                    std::cout << termcolor::bold << termcolor::on_color<237> << termcolor::color<245> <<"~ " << treset;
                else
                    std::cout << termcolor::bold << termcolor::on_color<237> << termcolor::color<245> <<"  " << treset;
            }
            else if (map.getCellByCords(pos).getPassability()) {

                if(map.getCellByCords(pos).checkForEvent() ) {
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
                        case E_SHOP:
                            std::cout << on_grey << yellow << "$ " << treset;
                            break;
                        case E_SOULS:
                            std::cout << on_grey << yellow << "⛬ " << treset;
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
                std::cout << termcolor::on_color<240> << termcolor::color<180> << "⛰ " << treset;  //ᗑ
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
                      << "Шипы. Было неприятно. Вы получили " << DEFAULT_SPIKE_DAMAGE - player.getArmor() << " урона. \n" << treset;
            break;
        case E_HEAL:
            std::cout << termcolor::bold
                      << "Отлично! Ты нашел лечебное зелье и восстановил " << DEFAULT_HEALPOTION_HEAL << " ОЗ\n" << treset;
            break;
        case E_SHOP:
            std::cout << termcolor::bold
                      << "Возвращайтесь еще!" << treset;
            break;
        case E_SOULS:
            std::cout << termcolor::bold
                      << "После кратковременного странного ощущения вы на секунду услышали крики откуда-то изнутри себя."
                         " Вы поглотили чьи-то души. Может они для чего-то еще пригодятся? " << treset;
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
