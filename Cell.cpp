#include "Cell.h"

Cell::Cell(int type) : cellType(type){
    switch (cellType) {
        case 1:
            this->texture = '#';
            this->passability = true;
            break;
        case 2:
            this->texture = '^';
            this->passability = false;
            break;
        default:
            this->texture = '?';
            this->passability = true;
            break;
    }
}

void Cell::setPassability(bool newPassability) {
    passability=newPassability;
}

bool Cell::getPassability() {
    return passability;
}

unsigned int Cell::getCellType() {
    return cellType;
}

void Cell::setCellType(unsigned int newCellType) {
    cellType = newCellType;
}

void Cell::printCell() {
    std::cout<<texture;
}
