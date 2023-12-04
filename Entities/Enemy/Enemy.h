#ifndef LAB1_ENEMY_H
#define LAB1_ENEMY_H

#include "WanderingGhost/WGNavigation.h"


//template <class T1, class T2>
template <class T1>

class Enemy {
public:
    Enemy(int damage, int health, bool isMovable);

    void setDamage(int);
    bool getDamage();

    void setHealth();
    int getHealth();

    void setIsMovable(bool);
    bool getIsMovable();

    void setPosition(Position& newPos);
    Position& getPos();

    void move();

private:
    int damage{};
    int health{};

    bool isMovable{};

    Position entityPos;

    T1 navigation;
    //T2 interaction;
};


template <class T1>
Enemy<T1>::Enemy(int damage, int health, bool isMovable) {

    this->damage = damage;
    this->health = health;
    this->isMovable = isMovable;
}

template <class T1>
void Enemy<T1>::move() {
    T1::navigate(this->getPos());
}


template <class T1>
Position &Enemy<T1>::getPos() {
    return entityPos;
}

template <class T1>
void Enemy<T1>::setPosition(Position &newPos) {
    entityPos.x = newPos.x;
    entityPos.y = newPos.y;
}

#endif //LAB1_ENEMY_H