
#ifndef LAB1_POSITION_H
#define LAB1_POSITION_H


struct Position {
    int x, y;
    Position();
    bool operator == (const Position &p) const;
    bool operator != (const Position &p) const;
};


#endif //LAB1_POSITION_H
