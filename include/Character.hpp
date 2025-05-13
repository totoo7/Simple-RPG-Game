#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>

class Character {
    public:
        struct Point { unsigned int x, y; };
        enum WEAPON {
            SWORD,
            WAND,
            STAFF,
            AXE
        };
    public:
        Character(const char* name, Point pos, unsigned int hp, unsigned int dmg, WEAPON weapon);
        Character(const Character& rhs);
        Character& operator=(const Character& rhs);
        char* const get_name() const { return name; };
        Point get_pos() const { return position; };
        unsigned int get_hp() const { return health_points; };
        WEAPON get_weapon() { return weapon; };
        virtual unsigned int get_attack_damage() const { return attack_damage; };
        virtual void handle_attack(unsigned int dmg);
        virtual void attack(Character* const enemy);
        virtual void move(Point pos);
        virtual void print(std::ostream& os = std::cout) const;
        virtual Character* clone() const = 0;
        virtual ~Character();
    protected:
        bool in_range(Point point) const;
    protected:
        char* name = nullptr;
        Point position;
        unsigned int health_points;
        unsigned int attack_damage;
        WEAPON weapon;

};

#endif