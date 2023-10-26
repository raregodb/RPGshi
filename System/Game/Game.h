#ifndef LAB1_GAME_H
#define LAB1_GAME_H

#include <iostream>
#include <string>
#include "../../Entities/Player.h"
#include "../Navigation/Navigation.h"
#include "../Map/Map.h"
#include "../Map/MapGenerator/MapGenerator.h"
#include "Render/RenderGame.h"
#include <cstdlib>
#include "../InputReader/InputReader.h"
#include "SettingsMenu.h"


class Game {
public:
    Game();
    static bool getLoseState(Player& pPlayer);
    static bool getWinState(Player& pPlayer);

private:
    bool exit_state;
};


#endif //LAB1_GAME_H
