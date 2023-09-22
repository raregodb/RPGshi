#include "Map.h"

Map::Map(int X, int Y) : sizeX(X), sizeY(Y) {
    this->startPosition.x = 1;
    this->startPosition.y = 1;

    this->finishPosition.x = sizeX - 1;
    this->finishPosition.y = sizeY - 1;

    map = new Cell*[sizeX];
    for (int i = 0; i < sizeX; i++) {
        map[i] = new Cell[sizeY];
    }
}

Map::Map(const Map &oMap) {
    map = oMap.map;
    sizeX = oMap.sizeX;
    sizeY = oMap.sizeY;
}

Map::Map(Map &&movedMap) noexcept {
    map = movedMap.map;
    sizeX = movedMap.sizeX;
    sizeY = movedMap.sizeY;
    movedMap.map = nullptr;
}

Cell Map::getCellByCords(Position cords) {
    return map[cords.x][cords.y];
}

Map::~Map() {
    for (int i = 0; i < sizeX; i++) {
        delete[] map[i];
    }
    delete[] map;
}

int Map::getMapSizeByX() {
    return sizeX;
}

int Map::getMapSizeByY() {
    return sizeY;
}

Position Map::getPlayerStart() {
    return startPosition;
}

Position Map::getPlayerFinish() {
    return finishPosition;
}


