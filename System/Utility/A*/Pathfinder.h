#ifndef LAB1_PATHFINDER_H
#define LAB1_PATHFINDER_H

#include "../../Map/Map.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Node {
    Position position;
    int g, h;  // g - стоимость пути от старта до этой ячейки, h - эвристическая оценка до цели (например, расстояние по прямой)
    Node* parent;

    int f() const {
        return g + h;
    }
};

class Pathfinder {
public:
    Pathfinder(Map &map);

    std::vector<Position> findPath(Position start, Position goal);

    struct CompareNodes {
        bool operator()(const Node *a, const Node *b) const {
            return a->f() > b->f();
        }
    };

    bool isValid(const Position &pos);
private:
    Map &map;

    int heuristic(const Position &a, const Position &b);

    std::vector<Position> getNeighbors(const Position &pos);



    bool nodeInSet(const Position& pos, const std::priority_queue<Node*, std::vector<Node*>, CompareNodes>& nodeQueue);

    Node *findNode(const Position &pos, const std::priority_queue<Node *, std::vector<Node *>, CompareNodes> &nodeQueue);

};

#endif //LAB1_PATHFINDER_H
