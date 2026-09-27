#ifndef _DRAGON_HPP
#define _DRAGON_HPP

#include "creature.hpp"
#include <string>
#include <iostream>

class Dragon : public Creature {
    public:
       static Dragon* CreateOne() {
            std::string name = "Dragon-";
            name += std::to_string(char('A' + (char)(std::rand() & 0xF)));
            count_++;
            std::cout << "Now we have " << count_ << " Dragon instances." << std::endl;
            return new Dragon(name, std::rand() & 0x3F);
       }

       virtual const std::string WarCry() const {
            return "Whoosh!";
       }

       virtual ~Dragon() {
            std::cout << " Dragon instance : <" << count_ << "> deleted!\n";
            count_--;
       }

    private:
        static int count_;
        Dragon(const std::string& name, int hp) : Creature(name, "Dragon", hp) {}
};

#endif // !_DRAGON_HPP
