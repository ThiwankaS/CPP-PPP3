#ifndef _TROLL_HPP_ 
#define _TROLL_HPP_

#include "creature.hpp"
#include <string>

class Troll : public Creature {
    public:
        Troll(const std::string& name)
            : Creature(name, "Troll", 10) {}
        virtual std::string WarCry() const {
            return "Ugazaga!";
        }
        virtual Creature* Clone() const {
            return new Troll(*this);
        }
};
#endif // !_TROLL_HPP_
