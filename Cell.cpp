#include "Cell.h"

Cell::Cell(bool passability){
    this->passability = passability;
}

void Cell::setPassability(bool newPassability) {
    passability=newPassability;
}

bool Cell::getPassability() {
    return passability;
}
