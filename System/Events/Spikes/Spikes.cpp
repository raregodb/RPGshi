#include "Spikes.h"

Spikes::Spikes(Navigation& nav) : player(nav.getPlayer()) {
    this->Type = E_SPIKES;
    this->isDestructible = false;
}

void Spikes::someEvent() {
    player.takeDamage(DEFAULT_SPIKE_DAMAGE);
    player.addScore(1);
}

Event_Type Spikes::getType() {
    return Type;
}

bool Spikes::checkIsDesctructible() {
    return isDestructible;
}
