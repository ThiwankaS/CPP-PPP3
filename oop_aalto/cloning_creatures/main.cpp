#include <iostream>
#include <cstdlib>
#include <ostream>

#include "dragon.hpp"
#include "dungeon.hpp"
#include "troll.hpp"

int main(void) {

    Dungeon dung;

    Troll* tr = new Troll("Peikko");
    dung.AddCreature(tr);
    dung.AddCreature(new Dragon("Rhaegal"));

    //testing copy constuctor
    std::cout << "Copy constructor..." << std::endl;
    Dungeon other(dung);

    Dungeon third;
    third.AddCreature(new Dragon("Puff"));
    //testing copy assignment operator
    std::cout << "Copy assignment..." << std::endl;
    third = other;

    std::cout << "Program ending..." << std::endl;

    return EXIT_SUCCESS;
}
