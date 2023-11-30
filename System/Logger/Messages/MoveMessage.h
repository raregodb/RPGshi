#ifndef LAB1_MOVEMESSAGE_H
#define LAB1_MOVEMESSAGE_H

#include "IMesage.h"
#include "../../config/Input_Commands_Dir.h"
#include "../../ControlSettings/CommandReader/ConfigReader.h"

class MoveMessage : public IMessage{
public:
    MoveMessage(char key, std::string command);

    std::string getMessage() override;
private:
    char key;
    std::string command;
};


#endif //LAB1_MOVEMESSAGE_H
