#ifndef LAB1_INVENTORY_H
#define LAB1_INVENTORY_H

#include "map"
#include "Items.h"

class Inventory {
public:
    void addItem(items newItem);
    void incAmountOfItem(items item);
    void popItem(items item);
    void decItem(items item);
    void clearInventory();
    bool find(items item);
    int countItem(items item);

private:
    std::map<items, int> Inventory;
};


#endif //LAB1_INVENTORY_H
