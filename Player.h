#ifndef LAB1_PLAYER_H
#define LAB1_PLAYER_H

#include <string>
#include "Navigation.h"

#define DEFAULT_MAX_HEALTH 1000
#define DEFAULT_HEALTH 100
#define DEFAULT_DAMAGE 1
#define DEFAULT_SCORE 0
#define DEFAULT_CANBEDAMAGED 1
#define DEFAULT_ISDEAD 0



class Player {
private:
    int health;
    int maxHealth;
    int damage;
    int score;
    bool canBeDamaged;
    bool isDead;
    std::string nickname;


public:
    Player()
    {
        this->maxHealth=DEFAULT_MAX_HEALTH;
        this->health=DEFAULT_HEALTH;
        this->damage=DEFAULT_DAMAGE;
        this->score=DEFAULT_SCORE;
        this->nickname="undefined";
        this->canBeDamaged = DEFAULT_CANBEDAMAGED;
        this->isDead = DEFAULT_ISDEAD;
    }

    int getHealth();
    void setHealth(int newHealth);
    void addHealth(int addHealth);

    int getCharacterDamage();
    void setCharacterDamage(int newDamage);
    void takeDamage(int Damage);

    void addScore(int additionalScore);
    int getScore();
    void setScore(int newScore);

    bool getCanBeDamaged();
    void setCanBeDamaged(bool newCanBeDamaged);

    std::string getNickname();
    void setNickname(std::string newNickname);

    bool getIsDead();
    void setIsDead(bool newState);
};


#endif //LAB1_PLAYER_H
