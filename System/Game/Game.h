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
#include "../ControlSettings/InputReader/InputReader.h"
#include "../GameStates/GameState.h"
#include "../ControlSettings/CommandReader/ConfigReader.h"
#include "Render/EventStack.h"


class Game {
public:
    Game();

    void new_game(Player& player, Map& map, Navigation& navigation) const;
    static void interlayer(input_commands& input, Navigation& nav, Map& map, GameState& GS);

private:
    int mapSizeX;
    int mapSizeY;
    bool exitFlag;
};


#endif //LAB1_GAME_H
