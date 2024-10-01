#pragma once
#include <cmath>

struct Position
{
	int x;
	int y;

	Position(int x = 0, int y = 0) : x(x), y(y) {}

	double Distance(const Position& other) const {
		return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
	}

    void MoveTowards(const Position& target) {
        if (x < target.x) {
            x++;
        }
        else if (x > target.x) {
            x--;
        }

        if (y < target.y) {
            y++;
        }
        else if (y > target.y) {
            y--;
        }
    }
};