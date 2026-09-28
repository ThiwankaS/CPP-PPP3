#include "dungeon.hpp"
#include <iostream>

Dungeon::Dungeon(const Dungeon& d) {
    std::cout << "Copy constructor called" << std::endl;

    for(auto it : d.inhabitants_) {
        Creature* cr = it->Clone();
        inhabitants_.push_back(cr);
    }
}

Dungeon& Dungeon::operator=(const Dungeon& d) {
    std::cout << "Copy assigment called" << std::endl;

    // fir deleting the existing content
    for(auto it : inhabitants_) {
        std::cout << "Deleting " << it->GetName() << std::endl;
        delete it;
    }

    inhabitants_.clear();

    for(auto it : d.inhabitants_) {
        Creature* cr = it->Clone();
        inhabitants_.push_back(cr);
    } 
    return *this;
}
