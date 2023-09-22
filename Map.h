#ifndef LAB1_MAP_H
#define LAB1_MAP_H
#include "iostream"
#include "Cell.h"
#include "Position.h"

#define DEFAULTSIZEX 20
#define DEFAULTSIZEY 20

class Map {
public:
    Map(int x = DEFAULTSIZEX, int y = DEFAULTSIZEY);  //<--- конструктор

    Map(const Map &oMap);   //<--- конструктор копирования
    Map(Map &&moved) noexcept ;   //<--- конструктор перемещения

    Cell getCellByCords(Position cords);

    int getMapSizeByX();
    int getMapSizeByY();

    Position getPlayerStart();

    Position getPlayerFinish();

    ~Map();   //<--- деконструктор

private:
    Cell** map;
    int sizeX;
    int sizeY;
    Position startPosition;
    Position finishPosition;
};


#endif //LAB1_MAP_H
