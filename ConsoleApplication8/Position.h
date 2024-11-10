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

    void Save(std::ofstream& stream) const {
        if (stream.is_open()) {
            stream.write(reinterpret_cast<const char*>(&x), sizeof(int));
            stream.write(reinterpret_cast<const char*>(&y), sizeof(int));
        }
    }

    void Load(std::ifstream& stream) {
        if (stream.is_open()) {
            stream.read(reinterpret_cast<char*>(&x), sizeof(int));
            stream.read(reinterpret_cast<char*>(&y), sizeof(int));
        }
    }
};