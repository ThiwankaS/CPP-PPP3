#ifndef _DUNGEON_HPP_
#define _DUNGEON_HPP_

#include "creature.hpp"
#include <list>
#include <iostream>

class Dungeon {
    public:
        Dungeon () = default;
        ~Dungeon () {
            for(auto it : inhabitants_) {
                std::cout << "Deleting " << it->GetName() << std::endl;
                delete it;
            }
        }
        void AddCreature(Creature* m) {
            inhabitants_.push_back(m);
        }
    private:
        std::list<Creature*> inhabitants_;
};
#endif // !_DUNGEON_HPP_
