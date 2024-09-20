#pragma once

struct Position2d;

struct Map2d
{
	int minX;
	int minY;
	int maxX;
	int maxY;

	bool valid() const;
	bool contains(const Position2d& pos) const;
};
