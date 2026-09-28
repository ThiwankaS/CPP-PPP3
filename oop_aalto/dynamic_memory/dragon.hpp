#ifndef _DRAGON_HPP
#define _DRAGON_HPP

#include "creature.hpp"
#include <string>

class Dragon : public Creature {
    public:
        Dragon(const std::string&name) : Creature(name, "Dragon", 50) {}
        const std::string WarCry() const override {
            return "Whoosh!";
        }
};

#endif // !_DRAGON_HPP
