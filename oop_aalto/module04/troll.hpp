#ifndef _TROLL_HPP_
#define _TROLL_HPP_

#include "creature.hpp"

class Troll : public Creature {
    public:
        Troll(const std::string& name) : Creature(name, "Troll", 10) {
        }
};

#endif //! _TROLL_HPP_
