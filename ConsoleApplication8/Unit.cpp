#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Unit.h"

using namespace GameUnits;

Unit::Unit(const std::string& name, int hp, Weapon* weapon, const Position& position)
    : name(name), hp(hp > 0 ? hp : 100), weapon(weapon), position(position)
{

}

int Unit::GetHP() const
{
    return hp;
}

void Unit::SetHP(int value) {
    hp = value > 0 ? value : 100;
}

const std::string& Unit::GetName() const
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
    
}

void Unit::Save() {
    std::ofstream stream("udata.bin", std::ios::out | std::ios::binary);
    if (stream.is_open()) {
        Save(stream);
    }
}

void Unit::Save(std::ofstream& stream) const {
    if (stream.is_open()) {
        size_t nameSize = name.size();
        stream.write(reinterpret_cast<const char*>(&nameSize), sizeof(size_t));
        stream.write(name.c_str(), nameSize);

        stream.write(reinterpret_cast<const char*>(&hp), sizeof(int));

        if (weapon) {
            bool hasWeapon = true;
            stream.write(reinterpret_cast<const char*>(&hasWeapon), sizeof(bool));
            weapon->Save(stream);
        }
        else {
            bool hasWeapon = false;
            stream.write(reinterpret_cast<const char*>(&hasWeapon), sizeof(bool));
        }

        position.Save(stream);
    }
}

void Unit::Load() {
    std::ifstream stream("unit_data.bin", std::ios::in | std::ios::binary);
    if (stream.is_open()) {
        Load(stream);
    }
}

void Unit::Load(std::ifstream& stream) {
    if (stream.is_open()) {
        size_t nameSize;
        stream.read(reinterpret_cast<char*>(&nameSize), sizeof(size_t));

        char* buffer = new char[nameSize + 1];
        stream.read(buffer, nameSize);
        buffer[nameSize] = '\0';
        name = std::string(buffer);
        delete[] buffer;

        stream.read(reinterpret_cast<char*>(&hp), sizeof(int));

        bool hasWeapon;
        stream.read(reinterpret_cast<char*>(&hasWeapon), sizeof(bool));

        if (hasWeapon) {
            if (!weapon) {
                weapon = new Weapon("", 0);
            }
            weapon->Load(stream);
        }
        else {
            delete weapon;
            weapon = nullptr;
        }

        position.Load(stream);
    }
}

