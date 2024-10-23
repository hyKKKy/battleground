#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Unit.h"

using namespace GameUnits;

Unit::Unit(const char* name, int hp, Weapon* weapon, const Position& position)
    : hp(hp > 0 ? hp : 100), weapon(weapon), position(position)
{
    int len = std::strlen(name) + 1;
    this->name = new char[len];
    std::strcpy(this->name, name);
}

int Unit::GetHP() const
{
    return hp;
}

void Unit::SetHP(int value) {
    hp = value > 0 ? value : 100;
}

const char* Unit::GetName() const
{
    return name;
}

void Unit::Attack(Unit& enemy) {

    if (&enemy == this || enemy.GetHP() == 0 || hp == 0) {
        return;
    }
    int damage = weapon->GetDamage();
    std::cout << this->name << " Attack " << enemy.GetName() << std::endl;
    enemy.Damaged(damage);

}

void Unit::Damaged(int value) {
    if (hp - value <= 0) {
        hp = 0;
        std::cout << this->name << " was killed" << std::endl;
    }
    else
    {
        hp -= value;
        std::cout << this->name << " wounded on: " << value << " Health: " << hp << std::endl;
    }
}

Position Unit::GetPosition() const {
    return position;
}

void Unit::SetPosition(const Position& new_position) {
    position = new_position;
}

void Unit::MoveTowards(Unit& target) {
    std::cout << this->name << " is moving towards " << target.GetName() << std::endl;
    position.MoveTowards(target.GetPosition());
}

Unit::~Unit() {
    delete[] name;
}
