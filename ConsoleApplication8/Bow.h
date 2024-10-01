#pragma once
#include "Weapon.h"

class Bow : public Weapon
{
public:
    Bow(const char* name, int damage);
};