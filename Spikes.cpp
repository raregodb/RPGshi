#include "Spikes.h"
#include "Navigation.h"

Spikes::Spikes(Navigation& nav) : player(nav.getPlayer()) {
}

void Spikes::someEvent() {
    player.takeDamage(DEFAULT_CELL_DAMAGE);
    player.addScore(1);
    std::cout<<"\npizda\n";
}




