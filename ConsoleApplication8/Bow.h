#pragma once
#include "Weapon.h"

class Bow : public Weapon
{
public:
    Bow(const std::string& name, int damage);
};