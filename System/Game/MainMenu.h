#ifndef LAB1_MAINMENU_H
#define LAB1_MAINMENU_H

#include "iostream"
#include "../InputReader/InputReader.h"

#define WIDTH 30
#define HEIGHT 10

class MainMenu {
public:
    MainMenu();

    virtual void open();
    void print_menu(WINDOW *menu_win, int highlight, std::string* choices, int n_choices);

    virtual int getChoice();
    virtual void setChoice(int newChoice);

    int startx;
    int starty;
private:
    int n_choices;
    std::string menu_choices[3];
    int choice;
    WINDOW* Menu;
};


#endif //LAB1_MAINMENU_H
