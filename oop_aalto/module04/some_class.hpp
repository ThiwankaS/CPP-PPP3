#ifndef _SOME_CLASS_HPP_
#define _SOME_CLASS_HPP_

#include "creature.hpp"
#include <iostream>

class SomeClass {
    public:
        void check(const Creature& c) {
            std::cout << "GetName : " << c.name_ << "\n";
        }
};

#endif //define _SOME_CLASS_HPP_!_SOME_CLASS_HPP_

