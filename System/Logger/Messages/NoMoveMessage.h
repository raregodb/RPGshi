#ifndef LAB1_NOMOVEMESSAGE_H
#define LAB1_NOMOVEMESSAGE_H

#include "IMesage.h"

class NoMoveMessage : public IMessage{
public:
    NoMoveMessage(char key);

    std::string getMessage() override;
private:
    char key;
};




#endif //LAB1_NOMOVEMESSAGE_H
