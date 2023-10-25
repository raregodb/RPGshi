#include "Game.h"

Game::Game() {
    Player pPlayer; //создание игрока
    Map map(10, 7); //создание карты
    Navigation nav(pPlayer, map); //создание навигации
    MapGenerator GMap(map, nav); //генерация карты
    InputReader inputReader("../System/config/InputConfig.txt");
    RenderGame(nav, pPlayer, map);


    while(!getLoseState(pPlayer)) {
        if (getWinState(pPlayer)) {
            pPlayer.setIsFinished(false);
            MapGenerator GMap(map, nav); //генерация карты
            nav.setChPos(map.getPlayerStart());
            RenderGame(nav, pPlayer, map);
        }
        //nodelay(stdscr, TRUE);
        initscr(); //начало работы с curses.h
        cbreak(); /* Line buffering disabled. pass on everything */
        noecho(); //отключить отображение вводимых символов
        input_commands input = inputReader.ReadInput();
        //endwin();
        //refresh();

        switch (input) {
            case Left:
                //system("clear");
                nav.move(Left);
                RenderGame(nav, pPlayer, map);
                break;
            case Up:
                //system("clear");
                nav.move(Up);
                RenderGame(nav, pPlayer, map);
                break;
            case Right:
                //system("clear");
                nav.move(Right);
                RenderGame(nav, pPlayer, map);
                break;
            case Down:
                //system("clear");
                nav.move(Down);
                RenderGame(nav, pPlayer, map);
                break;
            case Escape:
//                system("clear");
//                nav.move(down);
//                RenderGame(nav, pPlayer, map);
                break;
            default:
                std::cout<<"bad input. use WASD\n";
                break;
        }
    }
}

bool Game::getLoseState(Player& pPlayer) {
    if (pPlayer.getIsDead()) {
        std::cout<<"Вы умерли :( \nИгра окончена\n";
        return true;
    }
    return false;
}

bool Game::getWinState(Player& pPlayer) {
    if (pPlayer.getIsFinished()) {
        std::cout<<"Вы прошли уровень!\nВы стали гораздо сильнее!\n";
        pPlayer.addScore(20);
        //pPlayer.setCharacterDamage(pPlayer.getCharacterDamage() + (pPlayer.getCharacterDamage() % 20));
        return true;
    }
    return false;
}

//void Game::execute_input(const std::string &input) {
//
//}
