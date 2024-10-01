#include "SwordMan.h"
#include <iostream>

SwordMan::SwordMan(const char* name, int hp, int power, Sword* sword)
    : Unit(name, hp, sword),
    power(power) {
}

void SwordMan::Attack(Unit& enemy) {
    if (&enemy == this || enemy.GetHP() == 0 || hp == 0) {
        return;
    }
    int damage = weapon->GetDamage() + power * 1.5;
    std::cout << this->GetName() << " Attack " << enemy.GetName() <<  std::endl;
    enemy.Damaged(damage);
}