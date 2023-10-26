#ifndef LAB1_MAINMENU_H
#define LAB1_MAINMENU_H

#include "iostream"
#include "IWindow.h"

class MainMenu : public IWindow {
public:
    MainMenu();

    void open() override;
    void print_window(WINDOW* window, int highlight, std::string* choices, int n_choices) override;

    int getChoice() override;
    void setChoice(int newChoice) override;
    WINDOW* getWindow();
    int getHighlight();
    std::string* getChoices();
    int get_n_choices();

private:
    std::string menu_choices[3];
    int choice;
    int n_choices;
    int highlight{};
    WINDOW* Menu{};
};


#endif //LAB1_MAINMENU_H
