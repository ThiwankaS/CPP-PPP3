#ifndef _DRAGON_HPP_
#define _DRAGON_HPP_

#include "creature.hpp"
#include <string>

class Dragon : public Creature {
    public:
        Dragon(const std::string& name)
            : Creature(name, "Dragon", 50) {}
        virtual std::string WarCry() const {
            return "Whoosh!";
        }
        virtual Creature* Clone() const {
            return new Dragon(*this);
        }
};

#endif // !_DRAGON_HPP_
