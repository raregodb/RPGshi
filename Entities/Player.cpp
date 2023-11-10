#include "Player.h"

#include "iostream"


Player::Player(int health, int damage, int score, int level) : health(health),
damage(damage), score(score), lvl(level) {
    this->maxHealth=DEFAULT_MAX_HEALTH;
    this->canBeDamaged = DEFAULT_CAN_BE_DAMAGED;
    this->isDead = DEFAULT_IS_DEAD;
    this->isFinished = DEFAULT_IS_FINISHED;
}

int Player::getHealth() const {
    return health;
}

void Player::setHealth(int newHealth) {
    if (newHealth < 0 || newHealth-health<0)
        std::cout<<"badHealth"<<std::endl; //Здесь выкидывать ошибку далее
    if (newHealth > maxHealth)
        health = maxHealth;
    else
        health = newHealth;
}

void Player::addHealth(int addHealth) {
    setHealth(health+addHealth);
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

int Player::getLevel() const {
    return lvl;
}

void Player::setLevel(int newLevel) {
    lvl = newLevel;
}

int Player::getMaxHealth() const {
    return maxHealth;
}

void Player::setMaxHealth(int newMax) {
    maxHealth = newMax;
}

void Player::initialize(Player &player) {
    player.health = DEFAULT_HEALTH;
    player.lvl = DEFAULT_LEVEL;
    player.maxHealth=DEFAULT_MAX_HEALTH;
    player.canBeDamaged = DEFAULT_CAN_BE_DAMAGED;
    player.isDead = DEFAULT_IS_DEAD;
    player.isFinished = DEFAULT_IS_FINISHED;
    player.score = DEFAULT_SCORE;
    player.damage = DEFAULT_DAMAGE;
}
