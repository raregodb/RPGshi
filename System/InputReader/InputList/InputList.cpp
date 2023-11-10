#include "InputList.h"

HashTable::HashTable() {
    table = std::vector<std::string>(250);
}

void HashTable::insert_item(int key, const std::string& command) {
    table.at(key) = command;
}

void HashTable::displayHash()
{
    for (int i = 0; i < table.size(); i++)
    {
        std::cout << "inputKey[" << i << "]";
        std::cout << " --> " << table.at(i);
        std::cout << std::endl;
    }
}

bool HashTable::find(int key) {
    for (int i = 0; i < table.size(); i++) {
        if (i == key && !table[i].empty()) {
            return true;
        }
    }
    return false;
}

std::string HashTable::getCommand(int key) {
    return table.at(key);
}

std::vector<std::string> HashTable::getTable() {
    return table;
}

int HashTable::count_command(const std::string& command) {
    int count = 0;
    for (int i = 0; i < table.capacity(); ++i) {
        if (table.at(i) == command)
            ++count;
    }
    return count;
}
