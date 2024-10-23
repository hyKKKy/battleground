#pragma once
#include "Unit.h"
#include "Bow.h"

namespace GameUnits{

    class Archer : public Unit
    {
    public:
        Archer(const char* name, int hp, int range, int arrows, Bow* bow);

        virtual void Attack(Unit& enemy);

        ~Archer();

    private:
        int range;
        int arrows;
    };
}