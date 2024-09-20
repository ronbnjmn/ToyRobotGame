#pragma once

#include <string>

// ToyRobotGameInputHandler - class that handles string user input

class ToyRobotGameInputHandler
{
public:
	virtual ~ToyRobotGameInputHandler() {};

	virtual void onUserInput(const std::string& input) = 0;
};
