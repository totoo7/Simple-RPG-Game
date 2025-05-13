#ifndef MAGE_HPP
#define MAGE_HPP

#include "Character.hpp"

class Mage : public Character {
    public:
        Mage(const char* name, Point pos, unsigned int hp, unsigned int dmg, WEAPON weapon, 
            const char* ability, double coefficient);
        Mage(const Mage& rhs);
        Mage& operator=(const Mage& rhs);
        void attack(Character* const enemy) override;
        void print(std::ostream& os = std::cout) const override;
        Character* clone() const override; 
        ~Mage();
    protected:
        double get_coefficient() const { return coefficient; };
        char* const get_ability() const { return ability; };
    private:
        char* ability;
        double coefficient;
};

#endif