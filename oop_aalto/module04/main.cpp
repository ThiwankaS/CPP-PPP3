#include "creature.hpp"
#include "dragon.hpp"
#include "troll.hpp"
#include "some_class.hpp"

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>

void print(const std::vector<Creature *>& monsters) {
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

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<Creature *> monsters;

    for(size_t i = 0; i < 10; i++) {
        monsters.push_back(Troll::CreateOne());
        monsters.push_back(Dragon::CreateOne());
    }

    print(monsters);

    for(auto it : monsters) {
        delete it;
    }

    return EXIT_SUCCESS;
}
