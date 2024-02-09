#ifndef LAB1_IRENDERGAME_H
#define LAB1_IRENDERGAME_H

#include "../../Navigation/Navigation.h"
#include "curses.h"
#include "../../../termcolor/termcolor.hpp"
#include "../../Events/Event_Types.h"
#include "../../Utility/Random.h"
#include "../../../Entities/Enemy/Enemy.h"

#define treset termcolor::reset
#define red termcolor::color<196>
#define blue termcolor::blue
#define cyan termcolor::cyan
#define yellow termcolor::yellow
#define violet termcolor::color<126>
#define green termcolor::color<118>
#define on_grey termcolor::on_grey

class IRenderGame {
    virtual void printInterface() const = 0;
    virtual void printMap() = 0;
    virtual void printEvent() = 0;
    virtual void printEvent(Event_Type TYPE) = 0;
    virtual void printGame() = 0;
    virtual void printWin() = 0;
};


#endif //LAB1_IRENDERGAME_H
