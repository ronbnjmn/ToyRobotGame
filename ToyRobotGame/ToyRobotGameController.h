#pragma once

#include <map>
#include <memory>
#include <string>
#include "Commands.h"
#include "ToyRobotGameInputHandler.h"

class ToyRobot;
class ToyRobotGameView;

// ToyRobotGameController implements ToyRobotGameInputHandler to handle string input
// and translates them into actions for its corresponding ToyRobot and ToyRobotGameView.

class ToyRobotGameController
	: public ToyRobotGameInputHandler
{
public:
	ToyRobotGameController(ToyRobot& _toyRobot, ToyRobotGameView& _view);

	void onUserInput(const std::string& input) override;

private:
	void initCommands();

	ToyRobot& toyRobot;
	ToyRobotGameView& view;

	std::map<std::string, std::unique_ptr<Command>> commands;

	bool toyRobotPlaced;
};
