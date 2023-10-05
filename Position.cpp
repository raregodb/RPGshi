
#include "Position.h"

Position::Position() {
    this->x=0;
    this->y=0;
}

bool Position::operator==(const Position &p) const {
    if (this->x == p.x && this->y == p.y) {
        return true;
    }
    else
        return false;
}

bool Position::operator!=(const Position &p) const {
    if (this->x != p.x || this->y != p.y) {
        return true;
    }
    else
        return false;
}
