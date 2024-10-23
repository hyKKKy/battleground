#pragma once
#include "Weapon.h"
#include "Position.h"

namespace GameUnits{

    class Unit
    {
    public:
        Unit(const char* name, int hp, Weapon* weapon, const Position& position = Position());

        int GetHP() const;

        void SetHP(int value);

        const char* GetName() const;

        virtual void Attack(Unit& enemy);

        void Damaged(int value);

        Position GetPosition() const;

        void SetPosition(const Position& newPosition);

         void MoveTowards(Unit& target);

        ~Unit();

    protected:
    
        int hp;
        char* name;
        Weapon* weapon;
        Position position;
    };
}