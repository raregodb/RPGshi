#ifndef LAB1_SETTINGSMENU_H
#define LAB1_SETTINGSMENU_H

#include "IWindow.h"
#include "../Logger/Log/ILogger.h"
#include "../Logger/Log/LogFile.h"
#include "../Logger/Log/Log.h"
#include "../Logger/Log/LogType.h"

class SettingsMenu : public IWindow {
public:
    SettingsMenu();
    void open() override;
    //void print_window(WINDOW* window, int highlight, std::string* choices, int n_choices) override;

    int getChoice() override;
    void setChoice(int newChoice) override;

    static void changeMapSize(int& x, int& y);
    LogType changeLoggerStream();


private:
    std::string settings_choices[3];
    LogType Ltype;
};


#endif //LAB1_SETTINGSMENU_H
