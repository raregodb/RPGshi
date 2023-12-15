#include "Pathfinder.h"

Pathfinder::Pathfinder(Map &map) : map(map) {
}

std::vector<Position> Pathfinder::findPath(Position start, Position goal) {
    std::vector<Position> path;

    std::priority_queue<Node*, std::vector<Node*>, CompareNodes> openSet;
    std::vector<Node*> closedSet;

    Node* startNode = new Node{start, 0, heuristic(start, goal), nullptr};
    openSet.push(startNode);

    while (!openSet.empty()) {
        Node* current = openSet.top();
        openSet.pop();

        if (current->position == goal) {
            // Построение пути, если цель достигнута
            while (current != nullptr) {
                path.push_back(current->position);
                current = current->parent;
            }
            std::reverse(path.begin(), path.end());
            break;
        }

        closedSet.push_back(current);

        for (auto& neighbor : getNeighbors(current->position)) {
            if (!isValid(neighbor)) {
                continue;
            }

            int tentativeG = current->g + 1; // В вашем случае, возможно, потребуется другая стоимость

            Node* neighborNode = findNode(neighbor, openSet);
            if (neighborNode == nullptr || tentativeG < neighborNode->g) {
                if (neighborNode == nullptr) {
                    neighborNode = new Node{neighbor, 0, 0, nullptr};
                }
                neighborNode->parent = current;
                neighborNode->g = tentativeG;
                neighborNode->h = heuristic(neighbor, goal);

                if (!nodeInSet(neighbor, openSet)) {
                    openSet.push(neighborNode);
                }
            }
        }
    }

    // Очистка памяти
    for (auto node : closedSet) {
        delete node;
    }

    return path;
}

std::vector<Position> Pathfinder::getNeighbors(const Position &pos) {
    // Получение соседей, например, соседи сверху, снизу, слева и справа
    std::vector<Position> neighbors;
    Position neighborPos;
    neighborPos.x = pos.x - 1;
    neighborPos.y = pos.y;
    neighbors.push_back(neighborPos);

    neighborPos.x = pos.x + 1;
    neighborPos.y = pos.y;
    neighbors.push_back(neighborPos);

    neighborPos.x = pos.x;
    neighborPos.y = pos.y - 1;
    neighbors.push_back(neighborPos);

    neighborPos.x = pos.x;
    neighborPos.y = pos.y + 1;
    neighbors.push_back(neighborPos);
    return neighbors;
}

int Pathfinder::heuristic(const Position &a, const Position &b) {
    // Просто евклидово расстояние в данном примере
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

bool Pathfinder::isValid(const Position &pos) {
    // Проверка, что позиция внутри карты и проходима
    return pos.x >= 0 && pos.x < map.getMapSizeByX()
    && pos.y >= 0 && pos.y < map.getMapSizeByY()
    && map.getCellByCords(pos).getPassability();
}

bool Pathfinder::nodeInSet(const Position& pos, const std::priority_queue<Node*, std::vector<Node*>, CompareNodes>& nodeQueue) {
    std::priority_queue<Node*, std::vector<Node*>, CompareNodes> tempQueue = nodeQueue;

    while (!tempQueue.empty()) {
        const Node* node = tempQueue.top();
        tempQueue.pop();

        if (node->position == pos) {
            return true;
        }
    }

    return false;
}

Node *Pathfinder::findNode(const Position &pos,
                           const std::priority_queue<Node *, std::vector<Node *>, CompareNodes> &nodeQueue) {
    std::priority_queue<Node*, std::vector<Node*>, CompareNodes> tempQueue = nodeQueue;

    while (!tempQueue.empty()) {
        const Node* node = tempQueue.top();
        tempQueue.pop();

        if (node->position == pos) {
            return const_cast<Node*>(node);
        }
    }

    return nullptr;
}
