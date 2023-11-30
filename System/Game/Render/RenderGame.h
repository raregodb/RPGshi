#ifndef LAB1_RENDERGAME_H
#define LAB1_RENDERGAME_H

#include "IRenderGame.h"


class RenderGame : public IRenderGame {
public:
    RenderGame(Navigation& nNavigation, Player& pPlayer, Map& map, bool& Fog);

    void printInterface() const override;
    void printMap() override;
    void printEvent() override;
    void printEvent(Event_Type TYPE) override;
    void printGame() override;
    void printWin() override;


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
