#pragma once

#include <string>

class ToyRobotGameInputHandler
{
public:
	virtual ~ToyRobotGameInputHandler() {};

	virtual void onUserInput(const std::string& input) = 0;
};
