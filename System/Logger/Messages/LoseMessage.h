#ifndef LAB1_LOSEMESSAGE_H
#define LAB1_LOSEMESSAGE_H

#include "IMesage.h"

class LoseMessage : public IMessage{
public:
    explicit LoseMessage(Navigation& nav);

    std::string getMessage() override;

private:
    Navigation& navigation;
    Position DeathCell;
};


#endif //LAB1_LOSEMESSAGE_H
