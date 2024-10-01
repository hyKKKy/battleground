#include "Team.h"
#include <iostream>

Team::Team() {
	units = nullptr;
	size = 0;
}

Team::Team(Unit** units, int size) {
	this->units = units;
	units = nullptr;

}

void Team::Add(Unit& new_unit) {
	Unit** temp = units;
	int new_size = size + 1;
	units = new Unit*[new_size + 1];

	for (int i = 0; i < size; i++)
	{
		units[i] = temp[i];
	}
	units[new_size - 1] = &new_unit;
	size = new_size;
	delete[] temp;
}

void Team::Attack(Team& enemyTeam) {
	if (size == 0 || enemyTeam.size == 0) {
		return;
	}

	for (int i = 0; i < size; i++) {
		Unit* attacker = units[i];
		Unit* target = enemyTeam.units[RandomTarget(enemyTeam)];

		if (attacker && target) {
			double distance = attacker->GetPosition().Distance(target->GetPosition());
			std::cout << "Distance between " << attacker->GetName() << " and " << target->GetName() << ": " << distance << std::endl;

			attacker->Attack(*target);
		}
	}
}

int Team::RandomTarget(Team& units)
{
	return rand() % units.size;
}