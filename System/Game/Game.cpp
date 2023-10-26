#include "Game.h"


Game::Game() {
    this->exit_state = false;
    Player pPlayer; //создание игрока
    Map map(10, 10); //создание карты
    Navigation nav(pPlayer, map); //создание навигации

    MainMenu Menu;
    SettingsMenu SetMenu;
    while (1) {
        Menu.open();
        switch (Menu.getChoice()) {
            case 1:
                break;
            case 2:
                while(1) {
                    //SetMenu.open();
                    switch (SetMenu.getChoice()) {
                        case 1:
                            break;
                        case 2:
                            break;
                    }
                    if (SetMenu.getChoice() == 2)
                        break;
                }
                break;
            case 3:
                exit_state = true;
                break;
        }
        if (Menu.getChoice() == 1 || Menu.getChoice() == 3)
            break;
    }

    if (!exit_state) {
        MapGenerator(map, nav); //генерация карты
        InputReader inputReader("/Users/raregod/CLionProjects/lab1/System/config/InputConfig.txt");
        RenderGame(nav, pPlayer,map).printGame();
        initscr(); //начало работы с curses.h

        while(!getLoseState(pPlayer)) {
            if (getWinState(pPlayer)) {
                pPlayer.setIsFinished(false);
                MapGenerator(map, nav); //генерация карты
                nav.setChPos(map.getPlayerStart());
                RenderGame(nav, pPlayer, map).printGame();
            }
            cbreak(); /* Line buffering disabled. pass on everything */
            noecho(); //отключить отображение вводимых символов
            input_commands input = inputReader.ReadInput();
            endwin();

            switch (input) {
                case Left:
                    nav.move(Left);
                    RenderGame(nav, pPlayer, map).printGame();
                    break;
                case Up:
                    nav.move(Up);
                    RenderGame(nav, pPlayer, map).printGame();
                    break;
                case Right:
                    nav.move(Right);
                    RenderGame(nav, pPlayer, map).printGame();
                    break;
                case Down:
                    nav.move(Down);
                    RenderGame(nav, pPlayer, map).printGame();
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
        system("clear");
        std::cout<<"Вы прошли уровень!\nВы стали гораздо сильнее!\n";
        pPlayer.addScore(20);
        //pPlayer.setCharacterDamage(pPlayer.getCharacterDamage() + (pPlayer.getCharacterDamage() % 20));
        return true;
    }
    return false;
}
