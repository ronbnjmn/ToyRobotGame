#include "Position2d.h"

bool Position2d::operator==(const Position2d& other) const
{
	return x == other.x
		&& y == other.y
		&& direction == other.direction;
}

std::string Position2d::getDescription() const
{
	switch (direction)
	{
		case Direction::NORTH:
			return "NORTH";

		case Direction::EAST:
			return "EAST";

		case Direction::SOUTH:
			return "SOUTH";

		case Direction::WEST:
			return "WEST";
	}

	return "";
}

bool Position2d::setDirection(const std::string& description)
{
	if (description == "NORTH")
	{
		direction = Direction::NORTH;
		return true;
	}
	else if (description == "EAST")
	{
		direction = Direction::EAST;
		return true;
	}
	else if (description == "SOUTH")
	{
		direction = Direction::SOUTH;
		return true;
	}
	else if (description == "WEST")
	{
		direction = Direction::WEST;
		return true;
	}

	return false;
}
