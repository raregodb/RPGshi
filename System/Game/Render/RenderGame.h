#ifndef LAB1_RENDERGAME_H
#define LAB1_RENDERGAME_H

#include "../../Navigation/Navigation.h"
#include "curses.h"

class RenderGame {
public:
    RenderGame(Navigation& nNavigation, Player& pPlayer, Map& map);

    void printInterface() const;
    void printMap();
    void printEvent();

private:
    Navigation& navigation;
    Player& player;
    Map& map;
    int hp;
    int score;
    int damage;
};


#endif //LAB1_RENDERGAME_H
