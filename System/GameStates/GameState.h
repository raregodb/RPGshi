#ifndef LAB1_GAMESTATE_H
#define LAB1_GAMESTATE_H

#include "MainMenu.h"
#include "SettingsMenu.h"
#include "PauseMenu.h"
#include "GameOver.h"

enum GameState{
    MENU,
    GAME,
    NEW_GAME,
    SETTINGS,
    PAUSE,
    GAME_OVER,
    EXIT
};

#endif //LAB1_GAMESTATE_H
