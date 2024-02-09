#include "Player.h"

#include "iostream"


Player::Player(int health, int damage, int score, int level) : health(health),
damage(damage), score(score), lvl(level) {
    this->maxHealth=DEFAULT_MAX_HEALTH;
    this->canBeDamaged = DEFAULT_CAN_BE_DAMAGED;
    this->isDead = DEFAULT_IS_DEAD;
    this->isFinished = DEFAULT_IS_FINISHED;
    this->FOV = DEFAULT_FOV;
    this->souls = DEFAULT_SOULS;
    this->armor = DEFAULT_ARMOR;
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
    player.FOV = DEFAULT_FOV;
    player.inventory.clearInventory();
    player.souls = DEFAULT_SOULS;
    player.armor = DEFAULT_ARMOR;
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

void Player::addCharacterDamage(int addDamage) {
    setCharacterDamage(damage + addDamage);
}

void Player::takeDamage(int Damage) {
    if ((Damage - getArmor() <= 0)) {
        if (health - Damage <= 0) {
            health = 0;
            isDead = true;
        }
        else
            health -= Damage;
    }
    else {
        if ((health - (Damage - getArmor())) <= 0) {
            health = 0;
            isDead = true;
        }
        else
            health -= (Damage - getArmor());
    }

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

int Player::getFOV() const {
    return FOV;
}

void Player::setFOV(int newFOV) {
    FOV = newFOV;
}

Inventory* Player::getInventory() {
    return &inventory;
}

int Player::getSouls() const {
    return souls;
}

void Player::setSouls(int newSouls) {
    if (newSouls < 0 || newSouls-souls<0)
        souls = 0;
    else
        souls = newSouls;
}

void Player::addSouls(int addSouls) {
    setSouls(souls + addSouls);
}

void Player::takeSouls(int takenSouls) {
    if ((souls - takenSouls) >= 0) {
        souls -= takenSouls;
    }
}

bool Player::canAfford(int afSouls) const {
    if ((souls - afSouls) >= 0) {
        return true;
    }
    return false;
}

int Player::getArmor() {
    return armor;
}

void Player::setArmor(int newArmor) {
    if (newArmor < 0 || newArmor-armor<0)
        std::cout<<"badArmor"<<std::endl; //Здесь выкидывать ошибку далее
    else
        armor = newArmor;
}

void Player::addArmor(int addArmor) {
    setArmor(armor + addArmor);
}

