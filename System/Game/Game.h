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


class Game {
public:
    Game();

    //void execute_input(const std::string& input);
    static bool getLoseState(Player& pPlayer);
    static bool getWinState(Player& pPlayer);
};


#endif //LAB1_GAME_H
