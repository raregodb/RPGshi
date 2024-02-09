#ifndef LAB1_GAME_H
#define LAB1_GAME_H

#define DEFAULT_FOG true

#include <iostream>
#include <string>
#include "../../Entities/Player/Player.h"
#include "../Navigation/Navigation.h"
#include "../Map/Map.h"
#include "../Map/MapGenerator/MapGenerator.h"
#include "Render/RenderGame.h"
#include <cstdlib>
#include "../ControlSettings/InputReader/InputReader.h"
#include "../GameStates/GameState.h"
#include "../ControlSettings/CommandReader/ConfigReader.h"
#include "../../Entities/Player/Items.h"
#include "../Logger/Log/Log.h"
#include "../Logger/Log/LogFile.h"
#include "../Logger/Logger.h"
#include "../Utility/A*/Pathfinder.h"



class Game {
public:
    Game();

    void new_game(Player& player, Map& map, Navigation& navigation) const;
    static void interlayer(input_commands& input, Navigation& nav, GameState& GS,
                           std::map<int, std::string> keyList, char inputKey, LogType& LT);

    static void menu_logic(MainMenu& Menu, GameState& GS);
    static void gameOver_logic(GameOver& GameOver, GameState& GS);
    static void settings_logic(SettingsMenu& SetMenu, GameState& GS,
                               int& mapSizeX, int& mapSizeY, LogType& LT);
    static void pause_logic(PauseMenu& Pause, GameState& GS, Navigation& nav, Map& map);

private:
    int mapSizeX;
    int mapSizeY;
    bool exitFlag;
    LogType LogT;
    bool isFog;



};


#endif //LAB1_GAME_H
