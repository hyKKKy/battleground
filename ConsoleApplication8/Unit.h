#pragma once
#include "Weapon.h"
#include "Position.h"
#include <string>

namespace GameUnits{

    class Unit : public IFile
    {
    public:
        Unit(const std::string& name, int hp, Weapon* weapon, const Position& position = Position());

        int GetHP() const;

        void SetHP(int value);

        const std::string& GetName() const;

        virtual void Attack(Unit& enemy);

        void Damaged(int value);

        Position GetPosition() const;

        void SetPosition(const Position& newPosition);

         void MoveTowards(Unit& target);

         virtual void Save(std::ofstream& stream) const override;
         virtual void Save();
         virtual void Load(std::ifstream& stream) override;
         virtual void Load() override;

        ~Unit();

    protected:
    
        int hp;
        std::string name;
        Weapon* weapon;
        Position position;
    };
}