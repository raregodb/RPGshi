#ifndef LAB1_MAP_H
#define LAB1_MAP_H
#include "iostream"
#include "Cell.h"
#include "../Navigation/Position.h"

#define DEFAULTSIZEX 12
#define DEFAULTSIZEY 12
#define STARTPOSITIONX 1
#define STARTPOSITIONY 1
#define MAXMAPSIZE 32
#define MINMAPSIZE 5

class Map {
public:
    explicit Map(int x = DEFAULTSIZEX, int y = DEFAULTSIZEY);  //<--- конструктор

    Map(const Map &oMap);   //<--- конструктор копирования
    Map& operator = (const Map &oMap);  //<--- оператор присваивания
    Map(Map &&moved) noexcept;   //<--- конструктор перемещения
    Map& operator=(Map &&movedMap) noexcept;  //<--- оператор

    Cell &getCellByCords(Position cords);

    int getMapSizeByX() const;
    int getMapSizeByY() const;

    Position getPlayerStart();
    Position getPlayerFinish();

    void cleanMap();

    ~Map();   //<--- деструктор

private:
    Cell** map;
    int sizeX;
    int sizeY;
    Position startPosition;
    Position finishPosition;
};


#endif //LAB1_MAP_H
