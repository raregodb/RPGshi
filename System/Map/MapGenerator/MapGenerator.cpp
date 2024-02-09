#include "MapGenerator.h"

MapGenerator::MapGenerator(Map &map, Navigation &navigation) : map1(map), nav(navigation){
    this->countTeleports = 0;
    this->countSouls = 0;
    this->countEnemies = 0;

    this->percentageWGEnemy = 1;
    this->percentageSHEnemy = 5;

    if (nav.getPlayer().getLevel() >= 10)
        this->maxEnemies = nav.getPlayer().getLevel()/10;

    else
        this->maxEnemies = 0;
    this->maxSouls = (sqrt(map1.getMapSizeByX() * map1.getMapSizeByY()))/8;
    this->maxTeleports = (sqrt(map1.getMapSizeByX() * map1.getMapSizeByY()))/6;

    this->percentageTeleport = 28;
    this->percentageSouls = 29;
    if (nav.getPlayer().getLevel() >= 20) {
        this->percentageSpike = 57;
        this->percentageHeal = 32;
    }
    else {
        this->percentageSpike = (nav.getPlayer().getLevel()/2) + 47; //max +10
        this->percentageHeal = 42 - (nav.getPlayer().getLevel()/2); //max -10
    }


    GenerateWalls();
    map1.cleanMap();
    navigation.destroyEnemies();
    RandomGeneration();
    spawnEnemies();
    while (!isPath()) {
        map1.cleanMap();
        navigation.destroyEnemies();
        RandomGeneration();
        spawnEnemies();
    }

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
    Position random_pos_shop;

    countTeleports = 0;
    countSouls = 0;

    random_pos_shop.x = Random::getRandomGen(3, map1.getMapSizeByX()-2);
    random_pos_shop.y = Random::getRandomGen(3, map1.getMapSizeByY()-2);

    auto *shop = new Shop(nav);
    map1.getCellByCords(random_pos_shop).spawnEvent(shop);
    map1.getCellByCords(random_pos_shop).setHavingEvent(true);
    map1.getCellByCords(random_pos_shop).setPassability(true);

    int random_souls = Random::getRandomGen(1, 10);

    for (int x = 1; x < map1.getMapSizeByX()-1; x++) {
        for (int y = 1; y < map1.getMapSizeByY()-1; y++) {
            position.x = x;
            position.y = y;
            if (position == map1.getPlayerFinish()) {
                auto *exit = new Exit_event(nav);
                map1.getCellByCords(position).spawnEvent(exit);
                map1.getCellByCords(position).setHavingEvent(true);
                map1.getCellByCords(position).setPassability(true);
                break;
            }
            if (position != map1.getPlayerStart() && position != map1.getPlayerFinish() && !map1.getCellByCords(position).checkForEvent()) {
                int random_n = Random::getRandomGen(1, 100); // получение рандомного числа
                if (random_n <= 25) {
                    map1.getCellByCords(position).setPassability(false);
                }
                else {
                    if ((random_n <= percentageTeleport) && (countTeleports < maxTeleports)) {
                        auto *teleport = new Teleport(nav, map1);
                        map1.getCellByCords(position).spawnEvent(teleport);
                        map1.getCellByCords(position).setHavingEvent(true);
                        map1.getCellByCords(position).setPassability(true);
                        countTeleports++;
                    }
                    else if ((random_n <= percentageSouls) && (countSouls < maxSouls) &&
                    random_souls <= 8 && random_n > percentageTeleport && nav.getPlayer().getLevel() > 3) {
                        auto *souls = new Souls(nav);
                        map1.getCellByCords(position).spawnEvent(souls);
                        map1.getCellByCords(position).setHavingEvent(true);
                        map1.getCellByCords(position).setPassability(true);
                        countSouls++;
                    }
                    else if ((random_n <= percentageHeal)) {
                        auto *heal = new HealPotion(nav);
                        map1.getCellByCords(position).spawnEvent(heal);
                        map1.getCellByCords(position).setHavingEvent(true);
                        map1.getCellByCords(position).setPassability(true);
                    }
                    else if ((random_n <= percentageSpike)) {
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
            if (map1.getCellByCords(position).checkForEvent()) {
                if (map1.getCellByCords(position).getEvent()->getType() == E_TELEPORT)
                    arr[x][y] = -1;
            }
            if(!(map1.getCellByCords(position).getPassability()))
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

void MapGenerator::spawnEnemies() {
    countEnemies = 0;
    for (int x = 1; x < map1.getMapSizeByX()-1; x++) {
        for (int y = 1; y < map1.getMapSizeByY()-1; y++) {
            Position position;
            position.x = x;
            position.y = y;
            int random_n = Random::getRandomGen(1, 100);
            if (map1.getCellByCords(position).getPassability() &&
            map1.getPlayerStart() != position &&
                    !isSurroundedByWalls(position)) {
                if ((random_n <= percentageWGEnemy) && (countEnemies < maxEnemies)) {

                    nav.getWGEnemies().push_back(std::make_shared<Enemy < WGNavigation, WGInteraction>>(
                            100,
                            1,
                            true,
                            WANDERING_GHOST,
                            position,
                            map1,
                            nav.getPlayer(),
                            nav.getChPos()));
                    countEnemies++;
                }
                else if ((random_n <= percentageSHEnemy) && (countEnemies < maxEnemies)) {
                    nav.getSHEnemies().push_back(std::make_shared<Enemy<SHNavigation, SHInteraction>>(
                            50,
                            100,
                            true,
                            SOUL_HUNTER,
                            position,
                            map1,
                            nav.getPlayer(),
                            nav.getChPos()));
                    countEnemies++;
                }
            }
        }
    }
}

bool MapGenerator::isSurroundedByWalls(Position position) {
    Position tryPosition = position;
    int countUnaccessableDirections = 0;
    tryPosition.x++;
    if (!map1.getCellByCords(tryPosition).getPassability())
        countUnaccessableDirections++;
    tryPosition = position;
    tryPosition.y++;
    if (!map1.getCellByCords(tryPosition).getPassability())
        countUnaccessableDirections++;
    tryPosition = position;
    tryPosition.y--;
    if (!map1.getCellByCords(tryPosition).getPassability())
        countUnaccessableDirections++;
    tryPosition = position;
    tryPosition.x--;
    if (!map1.getCellByCords(tryPosition).getPassability())
        countUnaccessableDirections++;
    if (countUnaccessableDirections == 4)
        return true;
    return false;
}


