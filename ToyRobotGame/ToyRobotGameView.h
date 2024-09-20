#pragma once

struct Position2d;

// ToyRobotGameView - class that can report or display a Position2d

class ToyRobotGameView
{
public:
	virtual ~ToyRobotGameView() {};

	virtual void report(const Position2d& position) const = 0;
};
