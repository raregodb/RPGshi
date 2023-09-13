#include "Player.h"

#include <utility>
#include "iostream"

int Player::getHealth() {
    return health;
}

void Player::setHealth(int newHealth) {
    if (newHealth < 0 || newHealth > maxHealth)
        std::cout<<"badHealth"<<std::endl; //Здесь выкидывать ошибку далее
    else
        health = newHealth;
}


int Player::getCharacterDamage() {
    return damage;
}

void Player::setNickname(std::string newNickname){
    nickname = newNickname;
}

void Player::setCharacterDamage(int newDamage) {
    if (newDamage < 0)
        std::cout<<"badDamage"; //Здесь выкидывать ошибку далее
    else
        damage = newDamage;
}

void Player::takeDamage(int Damage) {
    if ((health - Damage) <= 0) {
        health = 0;
        isDead = true;
    }
    else
        health -= Damage;
}


void Player::addScore(int additionalScore) {
    score += additionalScore;
}

int Player::getScore(){
    return score;
}

void Player::setScore(int newScore){
    if (newScore < 0)
        std::cout<<"badScore"; //Здесь выкидывать ошибку далее
    else
        score = newScore;
}


bool Player::getCanBeDamaged() {
    return canBeDamaged;
}

void Player::setCanBeDamaged(bool newCanBeDamaged) {
    canBeDamaged = newCanBeDamaged;
}

std::string Player::getNickname() {
    return nickname;
}

bool Player::getIsDead() {
    return isDead;
}

void Player::setIsDead(bool newState) {
    isDead = newState;
}
