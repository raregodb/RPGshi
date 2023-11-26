#ifndef LAB1_IWINDOW_H
#define LAB1_IWINDOW_H

#include "curses.h"
#include "string"
#include "iostream"

//#define WIDTH 30
//#define HEIGHT 10

class IWindow {
public:
    virtual void open() = 0;
    virtual void print_window(WINDOW* window, int highlight, std::string* choices, int n_choices);

    virtual int getChoice() = 0;
    virtual void setChoice(int newChoice) = 0;

protected:
    int WIDTH = 30;
    int HEIGHT = 10;

    int startx;
    int starty;

    int n_choices;
    int choice;
    int highlight;
};


#endif //LAB1_IWINDOW_H
