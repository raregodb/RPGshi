#ifndef LAB1_NEWGAMEMESSAGE_H
#define LAB1_NEWGAMEMESSAGE_H

#include "IMesage.h"

class NewGameMessage : public IMessage{
public:
    explicit NewGameMessage(Map& nav);

    std::string getMessage() override;

    Map& getMap();
    Position getStartCell();
private:
    Map& map;
    Position StartCell;
};


#endif //LAB1_NEWGAMEMESSAGE_H
