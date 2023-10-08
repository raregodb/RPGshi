#include "Spikes.h"
#include "Navigation.h"

Spikes::Spikes(Navigation& nav) : player(nav.getPlayer()) {
}

void Spikes::someEvent() {
    std::cout<<"Шипы. Было неприятно. Вы получили " << DEFAULT_SPIKE_DAMAGE << " урона. \n\n";
    player.takeDamage(DEFAULT_SPIKE_DAMAGE);
    player.addScore(1);
}
