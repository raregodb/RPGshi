#ifndef LAB1_EXITMESSAGE_H
#define LAB1_EXITMESSAGE_H

#include "IMesage.h"

class ExitMessage : public IMessage{
    std::string getMessage() override;
};


#endif //LAB1_EXITMESSAGE_H
