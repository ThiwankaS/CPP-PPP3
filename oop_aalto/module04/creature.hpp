#ifndef _CREATURE_HPP_
#define _CREATURE_HPP_

#include <string>

class Creature {
    public:
        Creature(const std::string& name, const std::string& type, int hp)
            : name_(name), type_(type), hitpoints_(hp) {
        }

        const std::string& GetName() const { return name_; }
        const std::string& GetType() const { return type_; }
        int GetHitPoints() const { return hitpoints_; }

        virtual const std::string WarCry(void) const {
            return "(nothing!)";
        };

        virtual ~Creature() = default;

        friend class SomeClass;
        friend void print_temp(const Creature* c);
        
    private:
        std::string         name_;
        const std::string   type_;
        int                 hitpoints_;
};

#endif //! _CREATURE_HPP_
