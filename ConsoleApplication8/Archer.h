#pragma once
#include "Unit.h"
#include "Bow.h"

namespace GameUnits{

    class Archer : public Unit
    {
    public:
        Archer(const std::string& name, int hp, int range, int arrows, Bow* bow);

        virtual void Attack(Unit& enemy);

        ~Archer();

    private:
        int range;
        int arrows;
    };
}