#pragma once
#include "IFile.h"
#include<fstream>

class Weapon : public IFile
{
private:
    std::string name;
    int damage;
public:
    Weapon(const std::string& name, int damage);

    virtual void Save(std::ofstream& stream) const override;

    virtual void Save();

    virtual void Load(std::ifstream& stream) override;
    
    virtual void Load() override;

    int GetDamage() const;

    ~Weapon();
};