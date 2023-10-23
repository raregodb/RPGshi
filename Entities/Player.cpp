#include "Player.h"

#include "iostream"


Player::Player(int health, int damage, int score, std::string nickname) : health(health),
damage(damage), score(score), nickname(nickname) {
    this->maxHealth=DEFAULT_MAX_HEALTH;
    this->canBeDamaged = DEFAULT_CANBEDAMAGED;
    this->isDead = DEFAULT_ISDEAD;
}


int Player::getHealth() const {
    return health;
}

void Player::setHealth(int newHealth) {
    if (newHealth < 0 || newHealth > maxHealth || newHealth-health<0)
        std::cout<<"badHealth"<<std::endl; //Здесь выкидывать ошибку далее
    else
        health = newHealth;
}

void Player::addHealth(int addHealth) {
    setHealth(health+addHealth);
}

void Player::setNickname(std::string newNickname){
    nickname = newNickname;
}

int Player::getCharacterDamage() const {
    return damage;
}

void Player::setCharacterDamage(int newDamage) {
    if (newDamage < 0)
        std::cout<<"badDamage"<<std::endl; //Здесь выкидывать ошибку далее
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
    if (score+additionalScore<0)
        std::cout<<"badScore"<<std::endl; //Здесь выкидывать ошибку далее
    else
        score += additionalScore;
}

int Player::getScore() const{
    return score;
}

void Player::setScore(int newScore){
    if (newScore < 0)
        std::cout<<"badScore"; //Здесь выкидывать ошибку далее
    else
        score = newScore;
}


bool Player::getCanBeDamaged() const {
    return canBeDamaged;
}

void Player::setCanBeDamaged(bool newCanBeDamaged) {
    canBeDamaged = newCanBeDamaged;
}

std::string Player::getNickname() {
    return nickname;
}

bool Player::getIsDead() const {
    return isDead;
}

void Player::setIsDead(bool newState) {
    isDead = newState;
}

void Player::setIsFinished(bool newState) {
    this->isFinished = newState;
}

bool Player::getIsFinished() const {
    return this->isFinished;
}

