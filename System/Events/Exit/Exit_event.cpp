#include "Exit_event.h"

Exit_event::Exit_event(Navigation &nav) : player(nav.getPlayer()) {
    this->ID = 4;
}

void Exit_event::someEvent() {
    player.setIsFinished(true);
    player.addScore(20);
    player.setMaxHealth(player.getScore() * 5);
    player.setLevel(player.getLevel() + 1);
}

void Exit_event::printSomeEvent() {
    std::cout<<"Вы прошли уровень!\nВы стали гораздо сильнее!\n";
}

int Exit_event::getID() {
    return ID;
}
