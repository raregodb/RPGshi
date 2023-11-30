#ifndef LAB1_IMESAGE_H
#define LAB1_IMESAGE_H

#include "../../Navigation/Navigation.h"
#include "ostream"

class IMessage {
public:
    virtual std::string getMessage() = 0;
};

#endif //LAB1_IMESAGE_H
