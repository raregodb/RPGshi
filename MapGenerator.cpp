#include "MapGenerator.h"

MapGenerator::MapGenerator(Map &map, Navigation &navigation) : map1(map), nav(navigation){
    GenerateMap();
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

Map &MapGenerator::GenerateMap() {
    GenerateWalls();
    do {
        RandomGeneration();
    } while (isPath() != 1);
    return map1;
}

void MapGenerator::RandomGeneration() {




    Position position;
    //srand(time(nullptr));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);



    for (int x = 1; x < map1.getMapSizeByX()-1; x++) {
        for (int y = 1; y < map1.getMapSizeByY()-1; y++) {
            position.x = x;
            position.y = y;
            if (position != map1.getPlayerStart() && position != map1.getPlayerFinish()) {
                //srand(time(0));
                int random_n = dist(gen);
                Cell* c = &map1.getCellByCords(position);
                if (random_n <= 25) {
                    map1.getCellByCords(position).setPassability(false);
                }
                else {

                    if (random_n <= 30) {
                        Teleport teleport(nav, map1);
                        Teleport* tp = &teleport;
                        map1.getCellByCords(position).spawnEvent(tp);
                        map1.getCellByCords(position).setPassability(true);
                    }
                    else if (random_n <= 37) {
                        HealPotion heal(nav);
                        HealPotion* hp = &heal;
                        map1.getCellByCords(position).spawnEvent(hp);
                        map1.getCellByCords(position).setPassability(true);
                    }
                    else if (random_n <= 47) {
                        Spikes spikes(nav);
                        Spikes* sp = &spikes;
                        map1.getCellByCords(position).spawnEvent(sp);
                        map1.getCellByCords(position).setPassability(true);
                    }
                }
            }
        }
    }
}

bool MapGenerator::isPath() {
    Position position;
    int row = map1.getMapSizeByX()-1;
    int col = map1.getMapSizeByY()-1;
    int arr[row][col];
    for (int x = 1; x < row; x++) {
        for (int y = 1; y < col; y++) {
            position.x = x;
            position.y = y;
            if (map1.getCellByCords(position).getPassability())
                arr[x-1][y-1] = 0;
            else
                arr[x-1][y-1] = -1;
        }
    }

    // set arr[0][0] = 1
    arr[0][0] = 1;

    // Mark reachable (from top left) nodes
    // in first row and first column.
    for (int i = 1; i < row; i++)
        if (arr[i][0] != -1)
            arr[i][0] = arr[i - 1][0];

    for (int j = 1; j < col; j++)
        if (arr[0][j] != -1)
            arr[0][j] = arr[0][j - 1];

    // Mark reachable nodes in remaining
    // matrix.
    for (int i = 1; i < row; i++)
        for (int j = 1; j < col; j++)
            if (arr[i][j] != -1) {
                if (arr[i][j - 1] > arr[i - 1][j])
                    arr[i][j] = arr[i][j - 1];
                else
                    arr[i][j] = arr[i - 1][j];
            }


    // return yes if right bottom
    // index is 1
    return (arr[row - 1][col - 1] == 1);
}

Map &MapGenerator::getMap() {
    return map1;
}



