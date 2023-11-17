#include "Game.h"


Game::Game() {
    GameState GS = MENU;
    mapSizeX = DEFAULTSIZEX;
    mapSizeY = DEFAULTSIZEY;
    exitFlag = false;

    Player pPlayer; //создание игрока
    Map map(mapSizeX, mapSizeY); //создание карты
    Navigation nav(pPlayer, map); //создание навигации

    MainMenu Menu;
    SettingsMenu SetMenu;
    PauseMenu Pause;
    GameOver gameOver;

    while (!exitFlag) {
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
            case EXIT:
                system("clear");
                exitFlag = true;
                break;
            case NEXT_LEVEL:
                map.cleanMap();
                MapGenerator(map, nav); //генерация карты
                Navigation::initialize(nav);

                GS = GAME;
                break;
            case NEW_GAME:
                new_game(pPlayer, map, nav);

                GS = GAME;
                break;
            case GAME:
                RenderGame(nav, pPlayer,map).printGame();
                while (GS == GAME) {
                    InputReader basicInputReader;
                    ConfigReader basicKeyConfig;
                    basicKeyConfig.InputSettingsReader("/Users/raregod/CLionProjects/lab1/System/config/InputConfig.txt");
                    if (pPlayer.getIsFinished()) {
                        RenderGame(nav, pPlayer, map).printWin();
                        pPlayer.setIsFinished(false);
                    }
                    while(GS == GAME) {
                        if (pPlayer.getIsFinished()) {
                            GS = NEXT_LEVEL;
                            break;
                        }

                        if (pPlayer.getIsDead()) {
                            GS = GAME_OVER;
                            break;
                        }

                        initscr(); //начало работы с curses.h
                        cbreak(); /* Line buffering disabled. pass on everything */
                        noecho(); //отключить отображение вводимых символов
                        input_commands input = basicInputReader.read(basicKeyConfig.getKeyList());
                        endwin();

                        interlayer(input, nav, map, GS);

                        RenderGame(nav, nav.getPlayer(), map).printGame();
                    }
                }
                break;
        }
    }
}

void Game::new_game(Player &oPlayer, Map &oMap, Navigation &oNavigation) const {
    Player::initialize(oPlayer); //создание нового игрока
    oMap.cleanMap();
    oMap = Map(mapSizeX, mapSizeY);
    Navigation::initialize(oNavigation);
    MapGenerator(oMap, oNavigation);
}

void Game::interlayer(input_commands& input, Navigation& nav, Map& map, GameState& GS) {
    if (input == Left || input == Up || input == Right || input == Down) {
        nav.move(input);
    }
    else {
        switch (input) {
            case Escape:
                GS = PAUSE;
                break;
            default:
                break;
        }
    }
}
