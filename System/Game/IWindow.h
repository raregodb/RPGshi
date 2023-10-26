#ifndef LAB1_IWINDOW_H
#define LAB1_IWINDOW_H

#include "curses.h"
#include "string"

#define WIDTH 30
#define HEIGHT 10

class IWindow {
public:
    virtual void open();
    virtual void print_window(WINDOW* window, int highlight, std::string* choices, int n_choices);

    virtual int getChoice() = 0;
    virtual void setChoice(int newChoice) = 0;

    int startx;
    int starty;

    std::string menu_choices[3];
    WINDOW* Menu;
};


#endif //LAB1_IWINDOW_H
