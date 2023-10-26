#include "IWindow.h"

//void IWindow::open(WINDOW* window, int highlight, std::string* choices, int n_choices, int choice) {
//    //WINDOW *menu_win;
//    choice = 0;
//    highlight = 1;
//    int c;
//
//    initscr();
//    clear();
//    noecho();
//    cbreak();	/* Line buffering disabled. pass on everything */
//
//    window = newwin(HEIGHT, WIDTH, starty, startx);
//    keypad(this->Menu, TRUE);
//    mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
//    refresh();
//    print_window(window, highlight, choices, n_choices);
//    while(1)
//    {
//        c = wgetch(window);
//        switch(c)
//        {	case 119:
//                if(highlight == 1)
//                    highlight = n_choices;
//                else
//                    --highlight;
//                break;
//            case 115:
//                if(highlight == n_choices)
//                    highlight = 1;
//                else
//                    ++highlight;
//                break;
//            case 10:
//                choice = highlight;
//                break;
//            default:
//                refresh();
//                break;
//        }
//        print_window(window, highlight, choices, n_choices);
//        if(choice != 0)	/* User did a choice come out of the infinite loop */
//            break;
//    }
//    clrtoeol();
//    refresh();
//    endwin();
//}
//
//void IWindow::print_window(WINDOW *window, int highlight, std::string *choices, int n_choices) {
//    int x, y, i;
//
//    x = 5;
//    y = 2;
//    //box(menu_win, 0, 0); //обводка
//    for(i = 0; i < n_choices; ++i)
//    {	if(highlight == i + 1) /* High light the present choice */
//        {
//            wattron(window, A_REVERSE);
//            mvwprintw(window, y, x, "%s", choices[i].c_str());
//            wattroff(window, A_REVERSE);
//        }
//        else
//            mvwprintw(window, y, x, "%s", choices[i].c_str());
//        y += 2;
//    }
//    wrefresh(window);
//}
