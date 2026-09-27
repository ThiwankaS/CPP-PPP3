#ifndef _DRAGON_HPP
#define _DRAGON_HPP

#include "creature.hpp"

class Dragon : public Creature {
    public:
        Dragon(const std::string& name) : Creature(name, "Dragon", 50) {
        }
};

#endif // !_DRAGON_HPP
