#pragma once
#include "Unit.h"
#include "Sword.h"

class SwordMan : public Unit
{
public:
    SwordMan(const char* name, int hp, int power, Sword* sword);

    virtual void Attack(Unit& enemy);

private:
    int power;
};