#pragma once
#include <iostream>
#include "Unit.h"
#include "Array.h"

using namespace GameUnits;

namespace GameBattle{

	class Team
	{
	public:
		int RandomTarget(Team& units);

		Team();
	
		Team(const Array<Unit*>& units);

		Team(const Team& other) = delete;
		Team& operator=(const Team& other) = delete;

		void Add(Unit& new_unit);

		void Attack(Team& enemyTeam);

	private:
		Array<Unit*> units;
	};
}

