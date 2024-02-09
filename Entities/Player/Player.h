#ifndef LAB1_PLAYER_H
#define LAB1_PLAYER_H

#include <string>
//#include "../../System/Navigation/Navigation.h"
#include "Inventory.h"

#define DEFAULT_MAX_HEALTH 100
#define DEFAULT_HEALTH 100
#define DEFAULT_DAMAGE 10
#define DEFAULT_SCORE 0
#define DEFAULT_CAN_BE_DAMAGED 1
#define DEFAULT_IS_DEAD 0
#define DEFAULT_IS_FINISHED 0
#define DEFAULT_LEVEL 1
#define DEFAULT_FOV 3
#define DEFAULT_SOULS 1
#define DEFAULT_ARMOR 0

class Player {
private:
    int health;
    int maxHealth;
    int damage;
    int armor;
    int score;
    bool canBeDamaged;
    bool isDead;
    bool isFinished;
    int lvl;
    int FOV;
    int souls;

    Inventory inventory;

public:
    explicit Player(int health = DEFAULT_HEALTH, int damage = DEFAULT_DAMAGE,
           int score = DEFAULT_SCORE, int level = DEFAULT_LEVEL);

    int getHealth() const;
    void setHealth(int newHealth);
    void addHealth(int addHealth);

    int getCharacterDamage() const;
    void setCharacterDamage(int newDamage);
    void addCharacterDamage(int addDamage);

    void takeDamage(int Damage);

    int getArmor();
    void setArmor(int newArmor);
    void addArmor(int addArmor);

    void addScore(int additionalScore);
    int getScore() const;
    void setScore(int newScore);

    bool getCanBeDamaged() const;
    void setCanBeDamaged(bool newCanBeDamaged);

    bool getIsDead() const;
    void setIsDead(bool newState);

    bool getIsFinished() const;
    void setIsFinished(bool newState);

    int getLevel() const;
    void setLevel(int newLevel);

    int getMaxHealth() const;
    void setMaxHealth(int newMax);

    int getFOV() const;
    void setFOV(int newFOV);

    int getSouls() const;
    void setSouls(int newSouls);
    void addSouls(int addSouls);
    void takeSouls(int takenSouls);
    bool canAfford(int souls) const;

    Inventory* getInventory();

    static void initialize(Player& player);
};


#endif //LAB1_PLAYER_H
