#include "Warrior.hpp"

int main(int, char**){
    Warrior war1("war1", {1, 1}, 100, 20, Warrior::WEAPON::AXE, 50);
    Warrior war2("war2", {2, 1}, 100, 20, Warrior::WEAPON::AXE, 50);
    while (war1.get_hp() > 0) {
        war2.attack(&war1);
    }
    war2.attack(&war1);
    war1.attack(&war2);
    Warrior war3(war2);
    war1 = war3;
    war3.print();
}
