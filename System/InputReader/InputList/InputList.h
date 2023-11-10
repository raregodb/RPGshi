#ifndef LAB1_INPUTLIST_H
#define LAB1_INPUTLIST_H

#include "list"
#include "string"
#include "iostream"
#include "vector"

class HashTable {
    std::vector<std::string> table;
public:
    HashTable();

    void insert_item(int key, const std::string& command);
    void displayHash();
    bool find(int key);
    int count_command(const std::string &command);


    std::string getCommand(int key);
    std::vector<std::string> getTable();

    //~HashTable();
};



#endif //LAB1_INPUTLIST_H
