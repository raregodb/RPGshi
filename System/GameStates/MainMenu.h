#ifndef LAB1_MAINMENU_H
#define LAB1_MAINMENU_H

#include "iostream"
#include "IWindow.h"

class MainMenu : public IWindow {
public:
    MainMenu();

    void open() override;
    //void print_window(WINDOW* window, int highlight, std::string* choices, int n_choices) override;

    int getChoice() override;
    void setChoice(int newChoice) override;

private:
    std::string menu_choices[3];
};


#endif //LAB1_MAINMENU_H
