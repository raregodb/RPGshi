#include "Inventory.h"

void Inventory::addItem(items newItem) {
    Inventory.insert(std::pair<items, int>(newItem, 1));
}

void Inventory::incAmountOfItem(items item) {
    Inventory.find(item)->second++;
}

void Inventory::popItem(items item) {
    Inventory.erase(item);
}

void Inventory::decItem(items item) {
    if (Inventory.find(item)->second == 1)
        Inventory.erase(item);
    else
        Inventory.find(item)->second--;
}

void Inventory::clearInventory() {
    Inventory.clear();
}

bool Inventory::find(items item) {
    if (Inventory.find(item) != Inventory.end())
        return true;
    else
        return false;
}
