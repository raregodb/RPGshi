#ifndef LAB1_SETTINGSMENU_H
#define LAB1_SETTINGSMENU_H

#include "MainMenu.h"


class SettingsMenu : MainMenu {
public:
    SettingsMenu();
    void open() override;
    int getChoice() override;
    void setChoice(int newChoice) override;

private:
    std::string settings_choices[2];
    int n_choices;
    int choice;
};


#endif //LAB1_SETTINGSMENU_H
