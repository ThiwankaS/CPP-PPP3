#ifndef _TROLL_HPP_
#define _TROLL_HPP_

#include "creature.hpp"
#include <string>

class Troll : public Creature {
    public:
        Troll(const std::string& name) : Creature(name, "Troll", 10) {}
        virtual const std::string WarCry(void) const override {
            return "Ugazaga!";
        }    
};
#endif //! _TROLL_HPP_
