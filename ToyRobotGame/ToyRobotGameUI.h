#pragma once
#include "ToyRobotGameView.h"

#include <string>

class ToyRobotGameInputHandler;
struct Position2d;

// ToyRobotGameUI can receive input from stdin, and forwards them to its ToyRobotGameInputHandler.
// This class implements ToyRobotGameView to report/display a Position2d to stdout.

class ToyRobotGameUI
	: public ToyRobotGameView
{
public:
	ToyRobotGameUI();

	void setInputHandler(ToyRobotGameInputHandler& inputHandler);
	std::string receiveInput();
	void report(const Position2d& position) const override;

private:
	ToyRobotGameInputHandler* handler;
};
