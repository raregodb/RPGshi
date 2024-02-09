#include "LogMenu.h"

LogMenu::LogMenu() {
    this->highlight = 0;
    this->choice = 0;
    this->n_choices = 4;
    this->menu_choices[0] = "НИКУДА";
    this->menu_choices[1] = "В ФАЙЛ";
    this->menu_choices[2] = "В КОНСОЛЬ";
    this->menu_choices[3] = "В ФАЙЛ И КОНСОЛЬ";
    this->WIDTH = 22;
    this->HEIGHT = 11;
    startx = (80 - WIDTH) / 2;
    starty = (24 - HEIGHT) / 2;
}

void LogMenu::open() {
    WINDOW *logMenu;
    choice = 0;
    int highlight = 1;
    int c;

    initscr();
    clear();
    noecho();
    cbreak();	/* Line buffering disabled. pass on everything */

    logMenu = newwin(HEIGHT, WIDTH, starty, startx);
    keypad(logMenu, TRUE);
    refresh();
    print_window(logMenu, highlight, menu_choices, n_choices);
    while(1)
    {
        c = wgetch(logMenu);
        switch(c)
        {
            case KEY_UP:
                if(highlight == 1)
                    highlight = n_choices;
                else
                    --highlight;
                break;
            case KEY_DOWN:
                if(highlight == n_choices)
                    highlight = 1;
                else
                    ++highlight;
                break;
            case 119:
                if(highlight == 1)
                    highlight = n_choices;
                else
                    --highlight;
                break;
            case 87:
                if(highlight == 1)
                    highlight = n_choices;
                else
                    --highlight;
                break;
            case 83:
                if(highlight == n_choices)
                    highlight = 1;
                else
                    ++highlight;
                break;
            case 115:
                if(highlight == n_choices)
                    highlight = 1;
                else
                    ++highlight;
                break;
            case 10:
                choice = highlight;
                break;
            default:
                refresh();
                break;
        }
        beep();
        print_window(logMenu, highlight, menu_choices, n_choices);
        if(choice != 0)	/* User did a choice come out of the infinite loop */
            break;
    }
    clrtoeol();
    refresh();
    endwin();
}

int LogMenu::getChoice() {
    return choice;
}

void LogMenu::setChoice(int newChoice) {
    choice = newChoice;
}
