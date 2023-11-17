#ifndef LAB1_SHOPMENU_H
#define LAB1_SHOPMENU_H

#include "IWindow.h"
#include "../Utility/Random.h"

class ShopMenu : public IWindow{
public:
    ShopMenu();
    void open() override;

    int getChoice() override;
    void setChoice(int newChoice) override;

private:
    std::string shop_choices[3];
    std::string phrases[5];
    int random_phrase;
};


#endif //LAB1_SHOPMENU_H
