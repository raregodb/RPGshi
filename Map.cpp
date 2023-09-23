#include "Map.h"

Map::Map(int X, int Y) : sizeX(X), sizeY(Y) {
    std::cout<<"Construct "<<this<<std::endl;
    if (sizeX < 0 || sizeY < 0 || sizeX > MAXMAPSIZE || sizeY > MAXMAPSIZE){
        std::cout<<"badMap\n";
    }
    else {
        this->startPosition.x = STARTPOSITIONX;
        this->startPosition.y = STARTPOSITIONY;

        this->finishPosition.x = sizeX - 1;
        this->finishPosition.y = sizeY - 1;

        this->map = new Cell*[sizeX];
        for (int i = 0; i < sizeX; i++) {
            this->map[i] = new Cell[sizeY];
        }
    }
}

Map::Map(const Map &oMap)
:   startPosition(oMap.startPosition),
    finishPosition(oMap.finishPosition),
    sizeX(oMap.sizeX),
    sizeY(oMap.sizeY)
{
    std::cout<<"Copy Construct "<<this<<std::endl;
    delete[] map;
    this->map = new Cell*[oMap.sizeX];
    for (int i = 0; i < oMap.sizeX; i++) {
        this->map[i] = new Cell[oMap.sizeY];
        for (int j = 0; j < oMap.sizeY; j++) {
            this->map[i][j] = oMap.map[i][j];
        }
    }
}

Map& Map::operator=(const Map &oMap) {
    std::cout<<"Copy assignment "<<this<<std::endl;
    if (this != &oMap) {
        delete[] map;
        this->startPosition = oMap.startPosition;
        this->finishPosition = oMap.finishPosition;

        this->sizeX = oMap.sizeX;
        this->sizeY = oMap.sizeY;

        this->map = new Cell*[oMap.sizeX];
        for (int i = 0; i < oMap.sizeX; i++) {
            this->map[i] = new Cell[oMap.sizeY];
            for (int j = 0; j < oMap.sizeY; j++) {
                this->map[i][j] = oMap.map[i][j];
            }
        }
    }
    return *this;
}

Map::Map(Map &&movedMap) noexcept
:   map(movedMap.map),
    startPosition(movedMap.startPosition),
    finishPosition(movedMap.finishPosition),
    sizeX(movedMap.sizeX),
    sizeY(movedMap.sizeY)
{
    std::cout<<"Move construct "<<this<<std::endl;
    movedMap.map = nullptr;
    movedMap.sizeX = movedMap.sizeY = 0;
    movedMap.startPosition.x = movedMap.finishPosition.x =
            movedMap.startPosition.y = movedMap.finishPosition.y = 0;
}

Map& Map::operator=(Map &&movedMap)  noexcept {
    std::cout<<"Move assignment "<<this<<std::endl;
    if (this != &movedMap) {
        delete[] map;
        this->startPosition = movedMap.startPosition;
        this->finishPosition = movedMap.finishPosition;

        this->sizeX = movedMap.sizeX;
        this->sizeY = movedMap.sizeY;

        this->map = movedMap.map;

        movedMap.map = nullptr;
        movedMap.sizeX = movedMap.sizeY = 0;
        movedMap.startPosition.x = movedMap.finishPosition.x =
        movedMap.startPosition.y = movedMap.finishPosition.y = 0;
    }
    return *this;
}

Cell Map::getCellByCords(Position cords) {
    return map[cords.x][cords.y];
}

Map::~Map() {
    std::cout<<"Deconstruct "<<this<<std::endl;
    for (int i = 0; i < sizeX; i++) {
        delete[] map[i];
    }
    delete[] map;
}

int Map::getMapSizeByX() const {
    return sizeX;
}

int Map::getMapSizeByY() const {
    return sizeY;
}

Position Map::getPlayerStart() {
    return startPosition;
}

Position Map::getPlayerFinish() {
    return finishPosition;
}
