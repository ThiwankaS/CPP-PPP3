#include "creature.hpp"
#include "dragon.hpp"
#include "troll.hpp"
#include "some_class.hpp"

#include <cstdlib>
#include <iostream>
#include <vector>

void print(const std::vector<Creature>& monsters) {
    std::cout << "List of monsters : \n";
    if(monsters.empty()) {
        std::cout << "empty!\n";
        return;
    }
    for(auto monster : monsters) {
        print_temp(monster);
    }
}

int main(void) {
    Troll troll("Diiba");
    Dragon dragon("Rhaegal");

    Creature cr = troll;
    std::cout << troll.GetName() << " has " << troll.GetHitPoints() << " points\n";

    std::vector<Creature> monsters;
    monsters.push_back(troll);
    monsters.push_back(dragon);
    monsters.push_back(Dragon("Viserion"));

    print(monsters);

    SomeClass sc;
    sc.check(cr);

    return EXIT_SUCCESS;
}
