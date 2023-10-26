#include "Spikes.h"

Spikes::Spikes(Navigation& nav) : player(nav.getPlayer()) {
    this->ID = 2;
}

void Spikes::someEvent() {
    player.takeDamage(DEFAULT_SPIKE_DAMAGE);
    player.addScore(1);
}

void Spikes::printSomeEvent() {
    std::cout<<"Шипы. Было неприятно. Вы получили " << DEFAULT_SPIKE_DAMAGE << " урона. \n\n";
}

int Spikes::getID() {
    return ID;
}
