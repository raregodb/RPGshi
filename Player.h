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
    explicit Player(int health = DEFAULT_HEALTH, int damage = DEFAULT_DAMAGE,
           int score = DEFAULT_SCORE, std::string nickname = "undefined");

    int getHealth() const;
    void setHealth(int newHealth);
    void addHealth(int addHealth);

    int getCharacterDamage() const;
    void setCharacterDamage(int newDamage);
    void takeDamage(int Damage);

    void addScore(int additionalScore);
    int getScore() const;
    void setScore(int newScore);

    bool getCanBeDamaged() const;
    void setCanBeDamaged(bool newCanBeDamaged);

    std::string getNickname();
    void setNickname(std::string newNickname);

    bool getIsDead() const;
    void setIsDead(bool newState);

};


#endif //LAB1_PLAYER_H
