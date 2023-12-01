#ifndef LAB1_WINMESSAGE_H
#define LAB1_WINMESSAGE_H

#include "IMesage.h"

class WinMessage : public IMessage{
public:
    explicit WinMessage(Player& pl);

    std::string getMessage() override;

private:
    Player& player;
};


#endif //LAB1_WINMESSAGE_H
