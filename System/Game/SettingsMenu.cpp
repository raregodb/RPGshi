#include "SettingsMenu.h"

SettingsMenu::SettingsMenu() {
    n_choices = 2;
    startx = (80 - WIDTH) / 2;
    starty = (24 - HEIGHT) / 2;
    this->choice = 0;
    this->settings_choices[0] = "MAP SIZE";
    this->settings_choices[1] = "BACK";
}

void SettingsMenu::open() {
    WINDOW *settings_win;
    int highlight = 1;
    choice = 0;
    int c;
    initscr();
    clear();
    noecho();
    cbreak();	/* Line buffering disabled. pass on everything */
    settings_win = newwin(HEIGHT, WIDTH, starty, startx);
    keypad(settings_win, TRUE);
    mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
    refresh();
    MainMenu::print_menu(settings_win, highlight, settings_choices, n_choices);
    while(1)
    {
        c = wgetch(settings_win);
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
        MainMenu::print_menu(settings_win, highlight, settings_choices, n_choices);
        if(choice != 0)	/* User did a choice come out of the infinite loop */
            break;
    }
    clrtoeol();
    refresh();
    endwin();
}

int SettingsMenu::getChoice() {
    return this->choice;
}

void SettingsMenu::setChoice(int newChoice) {
    this->choice = newChoice;
}

void SettingsMenu::print_window(WINDOW *window, int highlight, std::string *choices, int n_choices) {
    IWindow::print_window(window, highlight, choices, n_choices);
}
