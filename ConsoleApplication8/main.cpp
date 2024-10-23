#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> 
#include "Team.h"
#include "Weapon.h"
#include "Sword.h"
#include "Bow.h"
#include "Unit.h"
#include "Archer.h"
#include"SwordMan.h"

int main()
{
    srand(time(0));

    Sword Sword1("Sword1", 20);
    Bow Bow1("Bow1", 15);

    GameUnits::Archer archer1("Bob", 100, 20, 200, &Bow1);
    GameUnits::SwordMan swordman1("Rex4", 100, 10, &Sword1);
    GameUnits::SwordMan swordman2("Rex1", 100, 20, &Sword1);
    GameUnits::SwordMan swordman3("Rex2", 100, 30, &Sword1);
    GameUnits::SwordMan swordman4("Rex3", 100, 40, &Sword1);

    GameBattle::Team team1;
    GameBattle::Team team2;

    /*team2.Add(archer1);
    team2.Add(swordman1);
    team2.Add(swordman2);
    team2.Add(swordman3);
    team2.Add(swordman4);

    std::cout << team1.RandomTarget(team2) << std::endl;*/

    archer1.SetPosition(Position(0, 0));
    swordman1.SetPosition(Position(5, 5));

    
    std::cout << "Distance between " << swordman1.GetName() << " & " << archer1.GetName() << ": "
        << swordman1.GetPosition().Distance(archer1.GetPosition()) << std::endl;

    
    while (swordman1.GetPosition().Distance(archer1.GetPosition()) > 0) {
        swordman1.MoveTowards(archer1);
        std::cout << "New distance: " << swordman1.GetPosition().Distance(archer1.GetPosition()) << std::endl;
    }

    std::cout << swordman1.GetName() << " reached " << archer1.GetName() << std::endl;

    archer1.Attack(swordman1);
    swordman1.Attack(archer1);
    swordman1.Attack(archer1);
    swordman1.Attack(archer1);
    swordman1.Attack(archer1);
    swordman1.Attack(archer1);
    swordman1.Attack(archer1);

    std::cout << "GG" << std::endl;

    return 0;
}
