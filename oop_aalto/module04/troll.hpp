#ifndef _TROLL_HPP_
#define _TROLL_HPP_

#include "creature.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

class Troll : public Creature {
    public:
        static Troll* CreateOne() {
            std::string name = "Troll-";
            name += std::to_string(char('A' + (char)(std::rand() & 0xF)));
            count_++;
            std::cout << "Now we have " << count_ << " Troll instances." << std::endl;
            return new Troll(name, std::rand() & 0x3F);
        }

        virtual const std::string WarCry(void) const {
            return "Ugazaga!";
        };
       
        virtual ~Troll() {
            std::cout << " Troll instance : <" << count_ << "> deleted!\n";
            count_--;
        }

    private:
        static int count_;

        Troll(const std::string& name, int hp) : Creature(name, "Troll", hp) {}
};

#endif //! _TROLL_HPP_
