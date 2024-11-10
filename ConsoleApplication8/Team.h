#pragma once
#include <iostream>
#include <vector>
#include "Unit.h"

using namespace GameUnits;

namespace GameBattle{

	class Team
	{
	public:
		int RandomTarget(Team& units);

		Team() = default;

		~Team() = default;

		Team(const Team& other) = delete;
		Team& operator=(const Team& other) = delete;

		void Add(Unit& new_unit);

		void Attack(Team& enemyTeam);

	private:
		std::vector<Unit*> units;
	};
}

