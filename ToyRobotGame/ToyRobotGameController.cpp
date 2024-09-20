#include "ToyRobotGameController.h"

#include <map>
#include <string>
#include "Commands.h"
#include "StringTokenizer.h"
#include "ToyRobot.h"
#include "ToyRobotGameView.h"

ToyRobotGameController::ToyRobotGameController(ToyRobot& _toyRobot, ToyRobotGameView& _view)
	: toyRobot(_toyRobot)
	, view(_view)
	, commands()
	, toyRobotPlaced(false)
{
	initCommands();
}

void ToyRobotGameController::onUserInput(const std::string& input)
{
	// Parse command and arguments
	StringTokenizer tokenizer(input);
	if (tokenizer.count() > 2) return;
	const auto& command = tokenizer[0];
	const auto& arguments = tokenizer.count() > 1 ? tokenizer[1] : "";

	// PLACE command should be the first command
	if (!toyRobotPlaced && command != "PLACE") return;

	// Execute command
	auto stringToCommand = commands.find(command);
	if (stringToCommand != commands.end()) {
		const auto success = stringToCommand->second->execute(arguments);
		if (success && !toyRobotPlaced) toyRobotPlaced = true;
	}
}

void ToyRobotGameController::initCommands()
{
	commands.emplace("PLACE", std::make_unique<PlaceCommand>(toyRobot));
	commands.emplace("MOVE", std::make_unique<MoveCommand>(toyRobot));
	commands.emplace("LEFT", std::make_unique<LeftCommand>(toyRobot));
	commands.emplace("RIGHT", std::make_unique<RightCommand>(toyRobot));
	commands.emplace("REPORT", std::make_unique<ReportCommand>(view, toyRobot));
}
