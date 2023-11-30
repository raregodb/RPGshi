#ifndef LAB1_LOSEMESSAGE_H
#define LAB1_LOSEMESSAGE_H

#include "IMesage.h"

class LoseMessage : public IMessage{
public:
    explicit LoseMessage(Navigation& nav, Player& player);

    std::string getMessage() override;

    Navigation& getNavigation();
    Position getDeathCell();
private:
    Navigation& navigation;
    Player& player;
    Position DeathCell;
};


#endif //LAB1_LOSEMESSAGE_H
