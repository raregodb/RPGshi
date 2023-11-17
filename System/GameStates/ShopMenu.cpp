#include "ShopMenu.h"

ShopMenu::ShopMenu() {
    this->highlight = 0;
    this->choice = 0;
    this->n_choices = 3;
    this->shop_choices[0] = "Купить фонарик";
    this->shop_choices[1] = "Улучшить ваше снаряжение";
    this->shop_choices[2] = "НАЗАД";
    startx = (80 - WIDTH) / 2;
    starty = (24 - HEIGHT) / 2;
    random_phrase = Random::getRandomGen(0, 4);

    this->phrases[0] = "Да, иногда можно и попутешествовать, но нельзя бродить по миру вечно. Даже тебя наверняка кто-нибудь ждет дома.";
    this->phrases[1] = "Те, кто всегда верят своим глазам, — глупцы.";
    this->phrases[2] = "Крошечное существо среди руин. Древнее существо что смеется над тобой. Ее слова мудры.";
    this->phrases[3] = "Здесь ничего не происходит, значит придется скоро двинуться дальше. Туда где я смогу одурачить..."
                       " Прости, помочь одураченным и несчастным, и научить их. Ха-Ха.";
    this->phrases[4] = "Добрый охотник, ты пришел... Скоро придет рассвет... Эта ночь и сон закончатся.";
}

void ShopMenu::open() {
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
    mvwprintw(initscr(), 1, 2, "В палатке посреди леса сидит нечто. Вы не осознаете, кто или что стоит перед вами.\n "
                               "\t\t\t  Впрочем, может оно и к лучшему?");
    mvwprintw(initscr(), starty + 10, 2, "<<%s>> - слышите вы, выходя из палатки",phrases[random_phrase].c_str());
    refresh();
    print_window(menu_win, highlight, shop_choices, n_choices);
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
        print_window(menu_win, highlight, shop_choices, n_choices);
        if(choice != 0)	/* User did a choice come out of the infinite loop */
            break;
    }
    clrtoeol();
    refresh();
    endwin();
}

int ShopMenu::getChoice() {
    return this->choice;
}

void ShopMenu::setChoice(int newChoice) {
    this->choice = newChoice;
}
