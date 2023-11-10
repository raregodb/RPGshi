#include "MainMenu.h"

MainMenu::MainMenu() {
    this->highlight = 0;
    this->choice = 0;
    this->n_choices = 3;
    this->menu_choices[0] = "PLAY";
    this->menu_choices[1] = "SETTINGS";
    this->menu_choices[2] = "EXIT";
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
    mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
    refresh();
    print_window(menu_win, highlight, menu_choices, n_choices);
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
