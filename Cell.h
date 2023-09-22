#ifndef LAB1_CELL_H
#define LAB1_CELL_H

#include "iostream"

class Cell {
public:
    Cell(bool passability = true);  //<--- конструктор

    void setPassability(bool newPassability);
    bool getPassability();

private:
    bool passability;
};


#endif //LAB1_CELL_H