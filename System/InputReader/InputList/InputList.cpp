#include "InputList.h"

InputList::InputList() {
    table = std::vector<std::string>(250);
}

void InputList::insert_item(int key, const std::string& command) {
    table.at(key) = command;
}

void InputList::displayHash()
{
    for (int i = 0; i < table.size(); i++)
    {
        std::cout << "inputKey[" << i << "]";
        std::cout << " --> " << table.at(i);
        std::cout << std::endl;
    }
}

bool InputList::find(int key) {
    for (int i = 0; i < table.size(); i++) {
        if (i == key && !table[i].empty()) {
            return true;
        }
    }
    return false;
}

std::string InputList::getCommand(int key) {
    return table.at(key);
}

int InputList::count_command(const std::string& command) {
    int count = 0;
    for (int i = 0; i < table.capacity(); ++i) {
        if (table.at(i) == command)
            ++count;
    }
    return count;
}
