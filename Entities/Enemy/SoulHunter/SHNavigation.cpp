#include "SHNavigation.h"

void SHNavigation::navigate(Position & position, Position& playerPosition, Map & map) {

    Pathfinder pathfinder(map);
    if (pathfinder.isValid(playerPosition)) {
        std::vector<Position> path = pathfinder.findPath(position, playerPosition);

        if (path.size() > 1)
            position = path.at(1);
    }

}
