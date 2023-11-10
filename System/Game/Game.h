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
#include "../GameStates/GameState.h"


class Game {
public:
    Game();

    void new_game(Player& player, Map& map, Navigation& navigation) const;

private:
    int mapSizeX;
    int mapSizeY;
    bool exitFlag;
};


#endif //LAB1_GAME_H
