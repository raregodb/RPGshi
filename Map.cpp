#include "Map.h"

Map::Map(int X, int Y) : sizeX(X), sizeY(Y) {
    this->startPosition.x = 1;
    this->startPosition.y = 1;

    this->finishPosition.x = sizeX - 1;
    this->finishPosition.y = sizeY - 1;

    Cell wall(2);
    Cell path(1);

    map = new Cell*[sizeX];
    for (int i = 0; i < sizeX; i++) {
        map[i] = new Cell[sizeY];
    }

    for (int x = 0; x < sizeX; x++) {
        for (int y = 0; y < sizeY; y++) {
            if (x == 0 || y == 0 || x == sizeX - 1 || y == sizeY - 1)
                map[x][y] = wall;
            else
                map[x][y] = path;
        }
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


void Map::printMap() {
    for (int y = 0; y < sizeY; y++) {
        for (int x = 0; x < sizeX; x++) {
            if (x == sizeX - 1){
                //std::cout<<map[x][y].getCellType()<<std::endl;
                map[x][y].printCell();
                std::cout<<std::endl;
            }

            else
            {
                map[x][y].printCell();
                //std::cout<<map[x][y].getCellType();
            }

        }
    }
}


Map::~Map() {
    for (int i = 0; i < sizeX; i++) {
        delete[] map[i];
    }
    delete[] map;
}


