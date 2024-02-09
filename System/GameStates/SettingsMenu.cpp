#include "SettingsMenu.h"

SettingsMenu::SettingsMenu() {
    this->Ltype = NoLog;
    n_choices = 3;
    this->WIDTH = 22;
    this->HEIGHT = 9;
    startx = (80 - WIDTH) / 2;
    starty = (24 - HEIGHT) / 2;
    this->choice = 0;
    this->settings_choices[0] = "РАЗМЕР КАРТЫ";
    this->settings_choices[1] = "ЛОГГИРОВАНИЕ";
    this->settings_choices[2] = "НАЗАД";
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
    //mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
    refresh();
    print_window(settings_win, highlight, settings_choices, n_choices);
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
        print_window(settings_win, highlight, settings_choices, n_choices);
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

void SettingsMenu::changeMapSize(int &x, int &y) {
    endwin();
    system("clear");

    int ptr_x;
    int ptr_y;

    std::cout<<"\n\n\n\n\n\t\t\t Введите новый размер карты\n (ввод в виде: 'x y' с размером от 5 до 33 с любой стороны): \n";

    while (true) {
        std::cout << "Введите первое число: ";
        if (std::cin >> ptr_x) {
            // Очищаем буфер ввода перед вводом второго числа
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Введите второе число: ";
            if (std::cin >> ptr_y) {
                break;  // Оба числа введены корректно, выходим из цикла
            } else {
                std::cin.clear();  // Сбрасываем флаг ошибки ввода
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Очищаем буфер ввода
                std::cout << "Ошибка! Введите корректное второе число." << std::endl;
            }
        } else {
            std::cin.clear();  // Сбрасываем флаг ошибки ввода
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Очищаем буфер ввода
            std::cout << "Ошибка! Введите корректное первое число." << std::endl;
        }
    }
    x = ptr_x;
    y = ptr_y;
}

//LogType SettingsMenu::changeLoggerStream() {
//    //endwin();
//    system("clear");
//
//    char input;
//
//    printw("\n\n\n\n\n\t Введите желаемый вывод логгера(номер желаемого потока). "
//           "\n\t\t\t 1) Никуда"
//           "\n\t\t\t 2) В файл"
//           "\n\t\t\t 3) В консоль"
//           "\n\t\t\t 4) В файл и консоль\n");
////    std::cout<<"\n\n\n\n\n\t Введите желаемый вывод логгера(номер желаемого потока). "
////               "\n\t\t\t 1) Никуда"
////               "\n\t\t\t 2) В файл"
////               "\n\t\t\t 3) В консоль"
////               "\n\t\t\t 4) В файл и консоль\n";
//
//    bool flag = true;
//    while (flag) {
//        input = getch();
//        switch (input) {
//            case '1':
//                Ltype = NoLog;
//                flag = false;
//                break;
//            case '2':
//                Ltype = FileLog;
//                flag = false;
//                break;
//            case '3':
//                Ltype = ConsoleLog;
//                flag = false;
//                break;
//            case '4':
//                Ltype = BothLog;
//                flag = false;
//                break;
//            default:
//                Ltype = NoLog;
//                break;
//        }
//    }
//    return Ltype;
//}


LogType SettingsMenu::changeLoggerStream() {
    LogMenu logMenu;
    bool flag = true;
    while (flag) {
        logMenu.open();
        switch (logMenu.getChoice()) {
            case 1:
                Ltype = NoLog;
                flag = false;
                break;
            case 2:
                Ltype = FileLog;
                flag = false;
                break;
            case 3:
                Ltype = ConsoleLog;
                flag = false;
                break;
            case 4:
                Ltype = BothLog;
                flag = false;
                break;
            default:
                break;
        }
    }
    return Ltype;
}