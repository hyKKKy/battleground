#include "Archer.h"
#include <iostream>

using namespace GameUnits;

Archer::Archer(const std::string& name, int hp, int range, int arrows, Bow* bow)
    : Unit(name, hp, bow),
    range(range > 0 ? range : 10),
    arrows(arrows > 0 ? arrows : 60) {

}

void Archer::Attack(Unit& enemy) {
    if (&enemy == this || enemy.GetHP() == 0 || hp == 0) {
        return;
    }
    int damage = weapon->GetDamage();
    arrows -= 1;
    std::cout << this->name << " Attack " << enemy.GetName() << ". Arrows left " << arrows << std::endl;
    enemy.Damaged(damage);
}

Archer::~Archer() = default;