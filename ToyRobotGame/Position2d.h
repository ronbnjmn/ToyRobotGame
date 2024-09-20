#pragma once

#include <string>

// Position2d represents a 2D position vector.
// It has X and Y coordinates and direction (north, east, west, south).

struct Position2d
{
	int x;
	int y;

	enum class Direction
	{
		NORTH,
		EAST,
		SOUTH,
		WEST
	} direction;

	bool operator==(const Position2d& other) const;

	std::string getDescription() const;
	bool setDirection(const std::string& description);
};
