#ifndef LAB1_CELL_H
#define LAB1_CELL_H

#include "iostream"

class Cell {
public:
    Cell(int type = 1);  //<--- конструктор

    void setPassability(bool newPassability);
    bool getPassability();

    unsigned int getCellType();
    void setCellType(unsigned int newCellType);

    void printCell();
private:
    bool passability;
    unsigned int cellType;
    char texture;
};


#endif //LAB1_CELL_H