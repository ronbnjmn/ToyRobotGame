#pragma once

struct Position2d;

// Map2d is a 2D coordinate plane bounded by four edges.

struct Map2d
{
	int minX;
	int minY;
	int maxX;
	int maxY;

	bool valid() const;
	bool contains(const Position2d& pos) const;
};
