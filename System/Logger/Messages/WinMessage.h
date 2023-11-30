#ifndef LAB1_WINMESSAGE_H
#define LAB1_WINMESSAGE_H

#include "IMesage.h"

class WinMessage : public IMessage{
public:
    explicit WinMessage(Player& pl);

    std::string getMessage() override;


    int getHealth();
    int getExperience();
    int getDamage();
    int getArmor();
    int getSouls();
    int getLevel();

private:
    Player& player;
};


#endif //LAB1_WINMESSAGE_H
