#include "creature.hpp"
#include <iostream>

void print_temp(const Creature* cr) {
    std::cout << cr->GetName() << " has " << cr->GetHitPoints() << " points and says: " << cr->WarCry() << "\n";
}

