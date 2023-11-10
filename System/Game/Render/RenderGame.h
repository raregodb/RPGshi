#ifndef LAB1_RENDERGAME_H
#define LAB1_RENDERGAME_H

#include "../../Navigation/Navigation.h"
#include "curses.h"
#include "../../../termcolor/termcolor.hpp"

#define treset termcolor::reset
#define red termcolor::color<196>
#define yellow termcolor::color<226>
#define violet termcolor::color<126>
#define green termcolor::color<118>
#define on_grey termcolor::on_grey


class RenderGame {
public:
    RenderGame(Navigation& nNavigation, Player& pPlayer, Map& map);

    void printInterface() const;
    void printMap();
    void printEvent();
    void printGame();
    void printWin();

private:
    Navigation& navigation;
    Player& player;
    Map& map;
    int hp;
    int score;
    int damage;
    int lvl;
};


#endif //LAB1_RENDERGAME_H
