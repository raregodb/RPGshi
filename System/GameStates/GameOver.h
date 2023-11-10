#ifndef LAB1_GAMEOVER_H
#define LAB1_GAMEOVER_H

#include "IWindow.h"
#include "../../termcolor/termcolor.hpp"
#include "chrono"
#include "thread"

class GameOver : public IWindow{
public:
    GameOver();

    static void print_death();
    void open() override;

    int getChoice() override;
    void setChoice(int newChoice) override;

private:
    std::string menu_choices[2];
};


#endif //LAB1_GAMEOVER_H
