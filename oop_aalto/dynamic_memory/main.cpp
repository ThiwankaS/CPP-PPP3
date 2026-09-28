#include "dragon.hpp"
#include "dungeon.hpp"
#include "troll.hpp"

#include <iostream>
#include <cstdlib>

int main(void) {
    Dungeon dun;

    Troll* tr = new Troll("Peikko");
    dun.AddCreature(tr);
    dun.AddCreature(new Dragon("Rhaegal"));
    return EXIT_SUCCESS;
}
