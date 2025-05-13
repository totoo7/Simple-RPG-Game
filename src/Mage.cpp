#include "Mage.hpp"
#include <cstring>

Mage::Mage(const char* name, Point pos, unsigned int hp, unsigned int dmg, WEAPON weapon, 
    const char* ability, double coefficient) : 
        Character(name, pos, hp, dmg, weapon) 
{
    try {
        this->ability = new char[strlen(ability)+1];
        strcpy(this->ability, ability);
        this->coefficient = coefficient;
    } catch (...) {
        delete[] ability;
    } 
}

Mage::Mage(const Mage& rhs) : Character(rhs) {
    try {
        ability = new char[strlen(rhs.ability)+1];
        strcpy(ability, rhs.ability);
        coefficient = rhs.coefficient;
    } catch(...) {
        delete[] ability;
    }
}

Mage& Mage::operator=(const Mage& rhs) {
    if (this == &rhs) return *this;
    char* temp = new (std::nothrow) char[strlen(rhs.ability)+1];
    if (!temp) throw std::bad_alloc();
    Character::operator=(rhs);
    delete[] ability;
    ability = temp;
    coefficient = rhs.coefficient;    
    return *this;
}

void Mage::attack(Character* const enemy) {
    if(in_range(enemy->get_pos()))
        enemy->handle_attack(get_attack_damage() + enemy->get_hp() * coefficient);
}

void Mage::print(std::ostream& os) const {
    os << "\nAbility: " << ability 
    << "\nCoefficient: " << coefficient;

}
Character* Mage::clone() const {
    return new Mage(*this);
}

Mage::~Mage() {
    delete[] ability;
}