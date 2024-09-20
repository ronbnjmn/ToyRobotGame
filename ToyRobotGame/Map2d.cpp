#include "Map2d.h"

#include "Position2d.h"

bool Map2d::valid() const
{
	return minY < maxY
		&& minX < maxX;
}

bool Map2d::contains(const Position2d& pos) const
{
	return valid()
		&& pos.y >= minY
		&& pos.y <= maxY
		&& pos.x >= minX
		&& pos.x <= maxX;
}
