#include "Game.h"


Game::Game() {
    GameState GS = MENU;
    mapSizeX = DEFAULTSIZEX;
    mapSizeY = DEFAULTSIZEY;
    exitFlag = false;
    Level = 0;

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
                //pPlayer.setIsFinished(false);
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
                while (GS == GAME) {
                    InputReader inputReader("/Users/raregod/CLionProjects/lab1/System/config/InputConfig.txt");
                    if (pPlayer.getIsFinished()) {
                        RenderGame(nav, pPlayer, map).printWin();
                        pPlayer.setIsFinished(false);
                    }
                    else
                        RenderGame(nav, pPlayer,map).printGame();
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
                                RenderGame(nav, pPlayer, map).printGame();
                                break;
                        }
                    }
                }
                break;
        }
    }
}
bool Game::getWinState(Player& pPlayer) {
    if (pPlayer.getIsFinished()) {
        system("clear");
        std::cout<<"Вы прошли уровень!\nВы стали гораздо сильнее!\n";
        pPlayer.addScore(20);
        pPlayer.setMaxHealth(pPlayer.getScore() * 5);
        pPlayer.setLevel(pPlayer.getLevel() + 1);
        return true;
    }
    return false;
}

void Game::new_game(Player &oPlayer, Map &oMap, Navigation &oNavigation) const {
    Player::initialize(oPlayer); //создание нового игрока
    oMap.cleanMap();
    oMap = Map(mapSizeX, mapSizeY);
    Navigation::initialize(oNavigation);
    MapGenerator(oMap, oNavigation);
}
