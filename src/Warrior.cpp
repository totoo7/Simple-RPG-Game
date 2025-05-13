#include "Warrior.hpp"

Warrior::Warrior(const char* name, Point pos, unsigned int hp, unsigned int dmg, WEAPON weapon, unsigned int armor) :
    Character(name, pos, hp, dmg, weapon), armor(armor) {}

Warrior::Warrior(const Warrior& rhs) : Character(rhs), armor(rhs.armor) {}

Warrior& Warrior::operator=(const Warrior& rhs) {
    if (this == &rhs) return *this;
    Character::operator=(rhs);
    armor = rhs.armor;
    return *this;
}

void Warrior::handle_attack(unsigned int dmg) {
    if (armor >= dmg) {
        armor -= dmg;
        return;
    }
    dmg -= armor;
    armor = 0;
    Character::handle_attack(dmg);
}

void Warrior::print(std::ostream& os) const {
    Character::print();
    os << "\nArmor: " << armor;
}

Character* Warrior::clone() const {
    return new Warrior(*this);
}