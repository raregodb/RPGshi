#ifndef LAB1_LOGMENU_H
#define LAB1_LOGMENU_H

#include "IWindow.h"

class LogMenu : public IWindow {
public:
    LogMenu();

    void open() override;

    int getChoice() override;
    void setChoice(int newChoice) override;

private:
    std::string menu_choices[4];
};


#endif //LAB1_LOGMENU_H
