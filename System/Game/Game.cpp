#include "Game.h"


Game::Game() {
    GameState GS = MENU;
    mapSizeX = 10;
    mapSizeY = 10;

    Player pPlayer; //создание игрока
    Map map(mapSizeX, mapSizeY); //создание карты
    Navigation nav(pPlayer, map); //создание навигации
    MapGenerator(map, nav); //генерация карты

    MainMenu Menu;
    SettingsMenu SetMenu;
    PauseMenu Pause;
    GameOver gameOver;

    while (1) {
        switch (GS) {
            case MENU:
                while (GS == MENU) {
                    Menu.open();
                    switch (Menu.getChoice()) {
                        case 1:
                            GS = NEW_GAME;
                            break;
                        case 2:
                            GS = SETTINGS;
                            break;
                        case 3:
                            GS = EXIT;
                            break;
                    }
                }
                break;
            case SETTINGS:
                while (GS == SETTINGS) {
                    SetMenu.open();
                    switch (SetMenu.getChoice()) {
                        case 1:
                            SetMenu.changeMapSize(mapSizeX, mapSizeY);
                            break;
                        case 2:
                            GS = MENU;
                            break;
                    }
                }
                break;
            case PAUSE:
                while (GS == PAUSE) {
                    Pause.open();
                    switch (Pause.getChoice()) {
                        case 1:
                            GS = NEW_GAME;
                            break;
                        case 2:
                            MapGenerator(map, nav);
                            nav.setChPos(map.getPlayerStart());
                            GS = GAME;
                            break;
                        case 3:
                            GS = MENU;
                            break;
                        case 4:
                            GS = GAME;
                            break;
                    }
                }
                break;
            case GAME_OVER:
                while (GS == GAME_OVER) {
                    gameOver.open();
                    switch (gameOver.getChoice()) {
                        case 1:
                            GS = NEW_GAME;
                            break;
                        case 2:
                            GS = MENU;
                            break;
                    }
                }
                break;
            case NEW_GAME:
                new_game(pPlayer, map, nav);

                GS = GAME;
                break;
            case GAME:
                while (GS == GAME) {
                    InputReader inputReader("/Users/raregod/CLionProjects/lab1/System/config/InputConfig.txt");
                    RenderGame(nav, pPlayer,map).printGame();

                    while(GS == GAME) {
                        if (getWinState(pPlayer)) {
                            pPlayer.setIsFinished(false);
                            MapGenerator(map, nav); //генерация карты
                            nav.setChPos(map.getPlayerStart());
                            RenderGame(nav, pPlayer, map).printGame();
                        }

                        if (pPlayer.getIsDead()) {
                            GS = GAME_OVER;
                            break;
                        }

                        initscr(); //начало работы с curses.h
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
                                GS = PAUSE;
                                break;
                            default:
                                std::cout<<"bad input. use WASD\n";
                                break;
                        }
                    }
                }
                break;
            case EXIT:
                break;
        }
        if (GS == EXIT)
            break;
    }
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

void Game::new_game(Player &oPlayer, Map &oMap, Navigation &oNavigation) const {
    Player player; //создание игрока
    oPlayer = player;
    Map map(mapSizeX, mapSizeY); //создание карты
    oMap = map;
    //Navigation nav(oPlayer, oMap); //создание навигации
    oNavigation.setChPos(oMap.getPlayerStart());
    MapGenerator(oMap, oNavigation);
}
