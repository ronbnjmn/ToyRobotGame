#pragma once

#include <string>

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
