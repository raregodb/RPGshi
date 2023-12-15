#ifndef LAB1_ENEMY_H
#define LAB1_ENEMY_H

//#include "../Player/Player.h"
#include "EnemyType.h"
//#include "../../System/Map/Map.h"
#include "../Enemy/WanderingGhost/WGNavigation.h"
#include "../Enemy/WanderingGhost/WGInteraction.h"
#include "../Enemy/SoulHunter/SHNavigation.h"
#include "../Enemy/SoulHunter/SHInteraction.h"

class Player;


template <class T1, class T2>
class Enemy {
public:
    Enemy(int damage,
          int health,
          bool isMovable,
          EnemyType enemyType,
          Position position,
          Map& map,
          Player& player,
          Position& playerPosition);

    void setDamage(int);
    int getDamage();

    void setHealth(int);
    int getHealth();

    void takeDamage(int dmg);

    void setIsMovable(bool);
    bool getIsMovable();

    bool getIsDead();

    void setPlayerKnownPos(Position& playerPos);
    void changePlayerPos(Position& playerPos, Position newPos);

    void setPosition(Position& newPos);
    Position& getPos();

    void move();
    void interact();


private:
    int damage{};
    int health{};
    bool isMovable{};
    bool isDead{};
    EnemyType enemyType;
    Position& playerPosition;

    Position entityPos;
    Map& map;
    Player& player;
};


template <class T1, class T2>
Enemy<T1, T2>::Enemy(int damage,
                     int health,
                     bool isMovable,
                     EnemyType enemytype,
                     Position position,
                     Map& map,
                     Player& player,
                     Position& playerPosition)  : map(map), player(player), playerPosition(playerPosition){
    this->enemyType = enemytype;
    this->damage = damage;
    this->health = health;
    this->isMovable = isMovable;
    this->entityPos = position;
    this->isDead = false;
}

template<class T1, class T2>
bool Enemy<T1, T2>::getIsDead() {
    return isDead;
}

template<class T1, class T2>
bool Enemy<T1, T2>::getIsMovable() {
    return isMovable;
}

template<class T1, class T2>
void Enemy<T1, T2>::setIsMovable(bool newState) {
    isMovable = newState;
}


template<class T1, class T2>
void Enemy<T1, T2>::takeDamage(int dmg) {
    if (health - dmg <= 0) {
        health = 0;
        isDead = true;
    } else
        health = health - dmg;
}

template<class T1, class T2>
void Enemy<T1, T2>::setHealth(int newHealth) {
    if (newHealth < 0)
        health = 0;
    health = newHealth;
}

template<class T1, class T2>
int Enemy<T1, T2>::getHealth() {
    return health;
}

template<class T1, class T2>
void Enemy<T1, T2>::setDamage(int newDamage) {
    damage = newDamage;
}

template<class T1, class T2>
int Enemy<T1, T2>::getDamage() {
    return damage;
}

template<class T1, class T2>
void Enemy<T1, T2>::changePlayerPos(Position &playerPos, Position newPos) {
    playerPos.x = newPos.x;
    playerPos.y = newPos.y;
}

template<class T1, class T2>
void Enemy<T1, T2>::setPlayerKnownPos(Position &playerPos) {
    playerPosition.x = playerPos.x;
    playerPosition.y = playerPos.y;
}

template <class T1, class T2>
void Enemy<T1, T2>::move() {
    T1::navigate(getPos(),playerPosition ,map);
}


template<class T1, class T2>
void Enemy<T1, T2>::interact() {
    T2::interact(player, playerPosition, *this);
}

template <class T1, class T2>
Position &Enemy<T1, T2>::getPos() {
    return entityPos;
}

template <class T1, class T2>
void Enemy<T1, T2>::setPosition(Position &newPos) {
    entityPos.x = newPos.x;
    entityPos.y = newPos.y;
}

#endif //LAB1_ENEMY_H