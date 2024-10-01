#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Weapon.h"

Weapon::Weapon(const char* name, int damage)
    : damage(damage > 0 ? damage : 5)
{
    int len = std::strlen(name) + 1;
    this->name = new char[len];
    std::strcpy(this->name, name);
}

int Weapon::GetDamage() const {
    return damage;
}

Weapon::~Weapon() {
    delete[] name;
}