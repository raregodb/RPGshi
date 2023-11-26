#ifndef LAB1_RENDERGAME_H
#define LAB1_RENDERGAME_H

#include "../../Navigation/Navigation.h"
#include "curses.h"
#include "../../../termcolor/termcolor.hpp"
#include "../../Events/Event_Types.h"
#include "../../Utility/Random.h"

#define treset termcolor::reset
#define red termcolor::color<196>
#define blue termcolor::blue
#define cyan termcolor::cyan
#define yellow termcolor::yellow
#define violet termcolor::color<126>
#define green termcolor::color<118>
#define on_grey termcolor::on_grey


class RenderGame {
public:
    RenderGame(Navigation& nNavigation, Player& pPlayer, Map& map, bool& Fog);

    void printInterface() const;
    void printMap();
    void printEvent();
    void printEvent(Event_Type TYPE);
    void printGame();
    void printWin();


private:
    Navigation& navigation;
    Player& player;
    Map& map;
    Cell* some_cell;
    int hp;
    int score;
    int damage;
    int lvl;
    int souls;
    int armor;
    int isFog;
};


#endif //LAB1_RENDERGAME_H
