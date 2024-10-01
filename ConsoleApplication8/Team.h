#pragma once
#include <iostream>
#include "Unit.h"


class Team
{
public:
	int RandomTarget(Team& units)
	{
		return rand() % units.size;
	}

	Team();
	
	Team(Unit** units, int size);

	Team(const Team& other) = delete;
	Team& operator=(const Team& other) = delete;

	void Add(Unit& new_unit);

	void Attack(Team& enemyTeam);

private:
	Unit** units;
	int size;

	
};

