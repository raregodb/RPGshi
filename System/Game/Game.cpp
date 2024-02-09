#include "Game.h"

Game::Game() {
    GameState GS = MENU;
    mapSizeX = DEFAULTSIZEX;
    mapSizeY = DEFAULTSIZEY;
    isFog = DEFAULT_FOG;
    exitFlag = false;


    Player pPlayer; //создание игрока
    Map map(mapSizeX, mapSizeY); //создание карты
    Navigation nav(pPlayer, map); //создание навигации

    LogT = NoLog;

    MainMenu Menu;
    SettingsMenu SetMenu;
    PauseMenu Pause;
    GameOver gameOver;



    while (!exitFlag) {

        WinMessage Wmessage(pPlayer);
        LoseMessage LMessage(nav);
        NewGameMessage newGameMessage(map);
        ExitMessage exitMessage;

        switch (GS) {

            case MENU:
                menu_logic(Menu, GS);
                break;

            case SETTINGS:
                settings_logic(SetMenu, GS, mapSizeX, mapSizeY, LogT);
                break;

            case PAUSE:
                pause_logic(Pause, GS, nav, map);
                break;

            case GAME_OVER:
                gameOver_logic(gameOver, GS);
                Logger(LogT, LMessage).log();

                break;

            case EXIT:
                system("clear");
                exitFlag = true;
                Logger(LogT, exitMessage).log();
                break;

            case NEXT_LEVEL:
                map.cleanMap();
                MapGenerator(map, nav); //генерация карты
                Navigation::initialize(nav);
                Logger(LogT, Wmessage).log();

                GS = GAME;
                break;

            case NEW_GAME:
                new_game(pPlayer, map, nav);
                Logger(LogT, newGameMessage).log();

                GS = GAME;
                break;

            case GAME:
                RenderGame(nav, pPlayer,map, isFog).printGame();
                while (GS == GAME) {
                    InputReader basicInputReader;
                    ConfigReader basicKeyConfig;
                    basicKeyConfig.InputSettingsReader("../System/config/InputConfig.txt");
                    if (pPlayer.getIsFinished()) {
                        RenderGame(nav, pPlayer, map, isFog).printWin();
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
                        //noecho(); //отключить отображение вводимых символов
                        input_commands input = basicInputReader.read(basicKeyConfig.getKeyList());
                        std::map<int, std::string> pair = *basicKeyConfig.getKeyList();
                        char inputKey = char(basicInputReader.getInput());
                        endwin();

                        interlayer(input, nav, GS, pair, inputKey, LogT);


                        for (int i = 0; i < nav.getWGEnemies().size(); ++i) {
                            nav.getWGEnemies().at(i)->move();
                            if (nav.getWGEnemies().at(i)->getPos() == nav.getChPos())
                                nav.getWGEnemies().at(i)->interact();
                        }
                        for (int i = 0; i < nav.getSHEnemies().size(); ++i) {
                            nav.getSHEnemies().at(i)->move();
                            if (nav.getSHEnemies().at(i)->getPos() == nav.getChPos())
                                nav.getSHEnemies().at(i)->interact();
                        }
                        nav.updateEnemy();
                        RenderGame(nav, nav.getPlayer(), map, isFog).printGame();


                    }
                }
                break;
        }
    }
}

void Game::new_game(Player &oPlayer, Map &oMap, Navigation &oNavigation) const {
    Player::initialize(oPlayer); //создание нового игрока
    oMap = Map(mapSizeX, mapSizeY);
    Navigation::initialize(oNavigation);
    MapGenerator(oMap, oNavigation);
}

void Game::interlayer(input_commands& input, Navigation& nav, GameState& GS,
                      std::map<int, std::string> keyList, char inputKey, LogType& LogT) {
    if (input == Left || input == Up || input == Right || input == Down) {
        nav.move(input);
        MoveMessage moveMessage(inputKey , keyList.find(inputKey)->second);
        Logger(LogT, moveMessage).log();
    }
    else {
        NoMoveMessage noMoveMessage(inputKey);
        switch (input) {
            case Escape:
                GS = PAUSE;
                break;
            case Default:
                Logger(LogT, noMoveMessage).log();
            default:
                break;
        }
    }
}

void Game::menu_logic(MainMenu& Menu, GameState& GS) {
    while(GS == MENU) {
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
}

void Game::settings_logic(SettingsMenu &SetMenu, GameState &GS, int& mapSizeX, int& mapSizeY, LogType& LT) {
    while (GS == SETTINGS) {
        SetMenu.open();
        switch (SetMenu.getChoice()) {
            case 1:
                SetMenu.changeMapSize(mapSizeX, mapSizeY);
                break;
            case 2:
                LT = SetMenu.changeLoggerStream();
            case 3:
                GS = MENU;
                break;
        }
    }
}

void Game::pause_logic(PauseMenu &Pause, GameState &GS, Navigation &nav, Map& map) {
    while (GS == PAUSE) {
        Pause.open();
        switch (Pause.getChoice()) {
            case 1:
                GS = NEW_GAME;
                break;
            case 2:
                Navigation::initialize(nav);
                MapGenerator(map, nav);
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
}

void Game::gameOver_logic(GameOver &gameOver, GameState &GS) {
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
}
