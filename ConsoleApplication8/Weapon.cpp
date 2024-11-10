#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Weapon.h"

Weapon::Weapon(const std::string& name, int damage)
    : name(name), damage(damage > 0 ? damage : 5)
{
 
}

int Weapon::GetDamage() const {
    return damage;
}

Weapon::~Weapon() {
    
}

 void Weapon::Load()  {
    std::ifstream stream("data.bin", std::ios::in | std::ios::binary);
    if (stream.is_open()) {
        Load(stream);
    }

}

  void Weapon::Load(std::ifstream& stream) 
 {
     if (stream.is_open() && stream.good()) {
         size_t size = 0;
         stream.read(reinterpret_cast<char*>(&size), sizeof(size_t));

         char* buffer = new char[size + 1];
         stream.read(buffer, size);
         buffer[size] = '\0';
         name = std::string(buffer);
         delete[] buffer;

         stream.read(reinterpret_cast<char*>(&damage), sizeof(int));
     }
 }

 void Weapon::Save() {

      std::ofstream stream("data.bin", std::ios::out | std::ios::binary);
      if (stream.is_open()) {
          Save(stream);
      }
  }

 void Weapon::Save(std::ofstream& stream) const {
     if (stream.is_open() && stream.good()) {
         size_t size = name.size();
         stream.write(reinterpret_cast<const char*>(&size), sizeof(size_t));
         stream.write(name.c_str(), size);
         stream.write(reinterpret_cast<const char*>(&damage), sizeof(int));
     }
 }