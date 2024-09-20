#pragma once

#include "Map2d.h"
#include "Position2d.h"

// ToyRobot has a Position2d and a Map2d, wherein its position is constrained.
// It can be placed, moved, turned, to any position within its map.

class ToyRobot
{
public:
	ToyRobot(const Map2d& map = { INT_MIN, INT_MIN, INT_MAX, INT_MAX });
	virtual ~ToyRobot() {};

	virtual bool place(const Position2d& pos);
	virtual void move();
	virtual void left();
	virtual void right();

	Position2d getPosition() const;

private:
	Map2d map;
	Position2d pos;
};
