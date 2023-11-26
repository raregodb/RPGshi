#include "MainMenu.h"

MainMenu::MainMenu() {
    this->highlight = 0;
    this->choice = 0;
    this->n_choices = 3;
    this->menu_choices[0] = "ИГРАТЬ";
    this->menu_choices[1] = "НАСТРОЙКИ";
    this->menu_choices[2] = "ВЫХОД";
    this->WIDTH = 22;
    this->HEIGHT = 9;
    startx = (80 - WIDTH) / 2;
    starty = (24 - HEIGHT) / 2;
}

void MainMenu::open() {
    WINDOW *menu_win;
    choice = 0;
    int highlight = 1;
    int c;

    initscr();
    clear();
    noecho();
    cbreak();	/* Line buffering disabled. pass on everything */

    menu_win = newwin(HEIGHT, WIDTH, starty, startx);
    keypad(menu_win, TRUE);
    //mvprintw(0, 0, "Используйте стрелки для навигации в игровых меню");
    refresh();
    print_window(menu_win, highlight, menu_choices, n_choices);
    while(1)
    {
        c = wgetch(menu_win);
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
        print_window(menu_win, highlight, menu_choices, n_choices);
        if(choice != 0)	/* User did a choice come out of the infinite loop */
            break;
    }
    clrtoeol();
    refresh();
    endwin();
}

int MainMenu::getChoice() {
    return this->choice;
}

void MainMenu::setChoice(int newChoice) {
    this->choice = newChoice;
}
