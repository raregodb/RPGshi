#include "PauseMenu.h"

PauseMenu::PauseMenu() {
    this->highlight = 0;
    this->choice = 0;
    this->n_choices = 4;
    this->pause_choices[0] = "НАЧАТЬ НОВУЮ ИГРУ";
    this->pause_choices[1] = "ПЕРЕЗАГРУЗИТЬ УРОВЕНЬ";
    this->pause_choices[2] = "ВЫХОД В ГЛАВНОЕ МЕНЮ";
    this->pause_choices[3] = "НАЗАД В ИГРУ";
    startx = (80 - WIDTH) / 2;
    starty = (24 - HEIGHT) / 2;
}

void PauseMenu::open() {
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
    mvprintw(0, 0, "По правилам перезагрузка уровня доступна только при технической невозможности играть дальше");
    refresh();
    print_window(menu_win, highlight, pause_choices, n_choices);
    while(1)
    {
        c = wgetch(menu_win);
        switch(c)
        {	case KEY_UP:
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
            case 27:
                choice = 4;
                break;
            case 10:
                choice = highlight;
                break;
            default:
                refresh();
                break;
        }
        beep();
        print_window(menu_win, highlight, pause_choices, n_choices);
        if(choice != 0)	/* User did a choice come out of the infinite loop */
            break;
    }
    clrtoeol();
    refresh();
    endwin();
}

int PauseMenu::getChoice() {
    return this->choice;
}

void PauseMenu::setChoice(int newChoice) {
    this->choice = newChoice;
}
