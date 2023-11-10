#ifndef LAB1_PAUSEMENU_H
#define LAB1_PAUSEMENU_H

#include "IWindow.h"

class PauseMenu : public IWindow{
public:
    PauseMenu();
    void open() override;
    //void print_window(WINDOW* window, int highlight, std::string* choices, int n_choices) override;

    int getChoice() override;
    void setChoice(int newChoice) override;

private:
    std::string pause_choices[4];
};


#endif //LAB1_PAUSEMENU_H
