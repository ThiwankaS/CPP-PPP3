#ifndef _CREATURE_HPP_ 
#define _CREATURE_HPP_

#include <string>

class Creature {
    public:
        Creature(const std::string& name, const std::string& type, int hit_points)
            : name_(name), type_(type), hitpoints_(hit_points) {}
        virtual ~Creature () {}

        const std::string& GetName() const { return name_; }
        const std::string& GetType() const { return type_; }
        int GetHitPoints() const { return hitpoints_; }
        
        virtual std::string WarCry() const {
            return "(Nothing)";
        }

        virtual Creature* Clone() const = 0;

    private:
        std::string name_;
        std::string type_;
        int hitpoints_;
};
#endif //! _CREATURE_HPP_
