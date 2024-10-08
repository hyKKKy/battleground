#include "Team.h"
#include <iostream>

Team::Team(): units() {}

Team::Team(const Array<Unit*>& units) {
	this->units = units;
}

void Team::Add(Unit& new_unit) {
	units.push_back(&new_unit); 
}

void Team::Attack(Team& enemyTeam) {
    if (units.get_size() == 0 || enemyTeam.units.get_size() == 0) {
        return;
    }

    for (size_t i = 0; i < units.get_size(); i++) {
        Unit* attacker = units[i];
        Unit* target = enemyTeam.units[RandomTarget(enemyTeam)];

        if (attacker && target) {
            double distance = attacker->GetPosition().Distance(target->GetPosition());
            std::cout << "Distance between " << attacker->GetName() << " and " << target->GetName() << ": " << distance << std::endl;

            attacker->Attack(*target);
        }
    }
}

int Team::RandomTarget(Team& units) {
    return rand() % units.units.get_size();
}