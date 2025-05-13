#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include "Character.hpp"

class Warrior : public Character {
    public:
        Warrior(const char* name, Point pos, unsigned int hp, unsigned int dmg, WEAPON weapon, unsigned int armor);
        Warrior(const Warrior& rhs);
        Warrior& operator=(const Warrior& rhs);
        void handle_attack(unsigned int dmg) override;
        void print(std::ostream& os = std::cout) const override;
        Character* clone() const override; 
        ~Warrior() = default;;
    private:
        unsigned int armor = 0;
};

#endif