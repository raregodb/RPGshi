#include "IWindow.h"

void IWindow::print_window(WINDOW *window, int highlight, std::string *choices, int n_choices) {
    int x, y, i;

    x = 5;
    y = 2;
    box(window, 2, 2); //обводка
    for(i = 0; i < n_choices; ++i)
    {	if(highlight == i + 1) /* High light the present choice */
        {
            wattron(window, A_REVERSE);
            mvwprintw(window, y, x, "%s", choices[i].c_str());
            wattroff(window, A_REVERSE);
        }
        else
            mvwprintw(window, y, x, "%s", choices[i].c_str());
        y += 2;
    }
    wrefresh(window);
}
