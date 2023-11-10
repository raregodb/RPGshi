#ifndef LAB1_CHASHTABLE_H
#define LAB1_CHASHTABLE_H

#include "list"
#include "string"
#include "iostream"
#include "vector"

class HashTable {
    int capacity;
    //std::list<std::string> *table;
    std::vector<std::string> table;
public:
    explicit HashTable(int size = 250);

    void insert_item(int key, const std::string& command);
    void displayHash();
    bool find(int key);
    int count_command(const std::string &command);


    std::string getCommand(int key);
    int getCapacity() const;
    std::vector<std::string> getTable();

    //~HashTable();
};



#endif //LAB1_CHASHTABLE_H
