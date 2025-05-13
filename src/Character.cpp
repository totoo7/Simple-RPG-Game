#include "Character.hpp"
#include <cstring>
#include <cmath>

Character::Character(const char* name, Point pos, unsigned int hp, unsigned int dmg, WEAPON weapon) {
    try {
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        position = pos;
        health_points = hp;
        attack_damage = dmg;
        this->weapon = weapon;
    } catch(...) {
        delete[] name;
        throw;
    }
}

Character::Character(const Character& rhs) {
    try {
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
        position = rhs.position;
        health_points = rhs.health_points;
        attack_damage = rhs.attack_damage;
        weapon = rhs.weapon;
    } catch (...) {
        delete[] name;
        throw;
    }
}

Character& Character::operator=(const Character& rhs) {
    if (this == &rhs) return *this;
    char* temp = new (std::nothrow) char[strlen(rhs.name)+1];
    if (!temp) throw std::bad_alloc();
    strcpy(temp, rhs.name);
    delete[] name;
    name = temp;
    position = rhs.position;
    health_points = rhs.health_points;
    attack_damage = rhs.attack_damage;
    weapon = rhs.weapon;
    return *this;
}

bool Character::in_range(Point point) const {
    return abs(position.x - point.x) + abs(position.y - point.y) == 1;
}

void Character::attack(Character* const enemy) {
    if (enemy->get_hp() == 0) {
        std::cout << "Enemy is already dead!\n";
        return;
    }
    if (health_points == 0) {
        std::cout << "Attacking character is dead!\n";
        return;
    }
    if (in_range(enemy->get_pos())) {
        enemy->handle_attack(attack_damage);
        std::cout << "Attack hit!\n";
        return;
    } 
    std::cout << "Not in range for attack\n";
}

void Character::handle_attack(unsigned int dmg) {
    if (health_points >= dmg) {
        health_points -= dmg;
        return;
    } 
    health_points = 0;
}

void Character::move(Point pos) {
    position.x += pos.x;
    position.y += pos.y;
}

void Character::print(std::ostream& os) const {
    os << name
    << "\nAttack power: " << attack_damage;
    os << "\nWeapon: ";
    if (weapon == 0) {
        os << "Sword";
    } else if (weapon == 1) {
        os << "Wand";
    } else if (weapon == 2) {
        os << "Staff";
    } else if (weapon == 3) {
        os << "Axe";
    }
    os << "\nPosition: <" << position.x << ", " << position.y << ">"
    << "\nHealth: " << health_points;
}

Character::~Character() {
    delete[] name;
}

