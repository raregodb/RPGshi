#ifndef LAB1_SHOPMENU_H
#define LAB1_SHOPMENU_H

#include "IWindow.h"
#include "../Utility/Random.h"
#include "../Events/Shop/Shop.h"
#include "../Navigation/Navigation.h"

#define TORCH_PRICE 10
#define TORCH_UPGRADE_PRICE 7
#define EQUIPMENT_UPGRADE_PRICE 5
#define MOUNTAIN_EQUIPMENT_PRICE 2

class ShopMenu : public IWindow{
public:
    explicit ShopMenu(Navigation& navigation);
    void open() override;
    void print_window(WINDOW* window, int highlight, std::string* choices, int n_choices) override;

    int getChoice() override;
    void setChoice(int newChoice) override;

private:
    std::string shop_choices[4];
    std::string phrases[5];
    int price[3];
    int random_phrase;

    Navigation& nav;
};


#endif //LAB1_SHOPMENU_H
