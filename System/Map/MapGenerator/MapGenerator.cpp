#include "MapGenerator.h"

MapGenerator::MapGenerator(Map &map, Navigation &navigation) : map1(map), nav(navigation){
    GenerateWalls();
    RandomGeneration();
    while (!isPath())
        RandomGeneration();
}

void MapGenerator::GenerateWalls() {
    Position position;
    for (int x = 0; x < map1.getMapSizeByX(); x++) {
        position.x = x;
        position.y = 0;
        map1.getCellByCords(position).setPassability(false);
        position.y = map1.getMapSizeByY()-1;
        map1.getCellByCords(position).setPassability(false);
    }
    for (int y = 0; y < map1.getMapSizeByY(); y++) {
        position.x = 0;
        position.y = y;
        map1.getCellByCords(position).setPassability(false);
        position.x = map1.getMapSizeByX()-1;
        map1.getCellByCords(position).setPassability(false);
    }
}

void MapGenerator::RandomGeneration() {
    Position position;
    std::random_device rd; //генерация сида
    std::mt19937 gen(rd()); //использование алгоритма Mersenne Twister на основе данного сида
    std::uniform_int_distribution<> dist(1, 100); //генерация рандомных значений на замкнутом интервале

    for (int x = 1; x < map1.getMapSizeByX()-1; x++) {
        for (int y = 1; y < map1.getMapSizeByY()-1; y++) {
            position.x = x;
            position.y = y;
            if (position != map1.getPlayerStart() && position != map1.getPlayerFinish()) {
                int random_n = dist(gen); // получение рандомного числа
                if (random_n <= 25) {
                    map1.getCellByCords(position).setPassability(false);
                }
                else {
                    if (random_n <= 28) {
                        auto *teleport = new Teleport(nav, map1);
                        map1.getCellByCords(position).spawnEvent(teleport);
                        map1.getCellByCords(position).setHavingEvent(true);
                        map1.getCellByCords(position).setPassability(true);
                    }
                    else if (random_n <= 35) {
                        auto *heal = new HealPotion(nav);
                        map1.getCellByCords(position).spawnEvent(heal);
                        map1.getCellByCords(position).setHavingEvent(true);
                        map1.getCellByCords(position).setPassability(true);
                    }
                    else if (random_n <= 40) {
                        auto *spikes = new Spikes(nav);
                        map1.getCellByCords(position).spawnEvent(spikes);
                        map1.getCellByCords(position).setHavingEvent(true);
                        map1.getCellByCords(position).setPassability(true);
                    }
                    else
                        map1.getCellByCords(position).setPassability(true);
                }
            }
        }
    }
}

bool MapGenerator::isPath() {
    Position position;
    int row = map1.getMapSizeByX()-2;
    int col = map1.getMapSizeByY()-2;
    int arr[row][col];
    for (int x = 0; x < row; x++) {
        for (int y = 0; y < col; y++) {
            position.x = x+1;
            position.y = y+1;
            if (map1.getCellByCords(position).getPassability())
                arr[x][y] = 0;
            else
                arr[x][y] = -1;
        }
    }
    arr[0][0] = 1;
    for (int i = 1; i < row; i++)
        if (arr[i][0] != -1)
            arr[i][0] = arr[i - 1][0];

    for (int j = 1; j < col; j++)
        if (arr[0][j] != -1)
            arr[0][j] = arr[0][j - 1];

    for (int i = 1; i < row; i++)
        for (int j = 1; j < col; j++)
            if (arr[i][j] != -1) {
                if (arr[i][j - 1] > arr[i - 1][j])
                    arr[i][j] = arr[i][j - 1];
                else
                    arr[i][j] = arr[i - 1][j];
            }

    return (arr[row - 1][col - 1] == 1);
}