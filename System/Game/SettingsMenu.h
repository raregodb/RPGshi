#ifndef LAB1_SETTINGSMENU_H
#define LAB1_SETTINGSMENU_H

#include "MainMenu.h"


class SettingsMenu : public IWindow {
public:
    SettingsMenu();
    void open() override;
    void print_window(WINDOW* window, int highlight, std::string* choices, int n_choices) override;
    int getChoice() override;
    void setChoice(int newChoice) override;

private:
    std::string settings_choices[2];
    int n_choices;
    int choice;
};


#endif //LAB1_SETTINGSMENU_H
