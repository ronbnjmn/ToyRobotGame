#include "Commands.h"

#include "StringTokenizer.h"
#include "ToyRobot.h"
#include "ToyRobotGameView.h"

//** PlaceCommand

PlaceCommand::PlaceCommand(ToyRobot& _toyRobot)
	: toyRobot(_toyRobot)
{
}

bool PlaceCommand::execute(const std::string& arguments)
{
	StringTokenizer tokens(arguments, ",");
	if (tokens.count() != 3) return false;

	try
	{
		Position2d pos;
		pos.x = std::stoi(tokens[0]);
		pos.y = std::stoi(tokens[1]);
		return pos.setDirection(tokens[2])
			&& toyRobot.place(pos);
	}
	catch (...)
	{
		return false;
	}
}

//** MoveCommand

MoveCommand::MoveCommand(ToyRobot& _toyRobot)
	: toyRobot(_toyRobot)
{
}

bool MoveCommand::execute(const std::string& arguments)
{
	if (!arguments.empty()) return false;

	toyRobot.move();
	return true;
}


//** LeftCommand

LeftCommand::LeftCommand(ToyRobot& _toyRobot)
	: toyRobot(_toyRobot)
{
}

bool LeftCommand::execute(const std::string& arguments)
{
	if (!arguments.empty()) return false;

	toyRobot.left();
	return true;
}


//** RightCommand

RightCommand::RightCommand(ToyRobot& _toyRobot)
	: toyRobot(_toyRobot)
{
}

bool RightCommand::execute(const std::string& arguments)
{
	if (!arguments.empty()) return false;

	toyRobot.right();
	return true;
}


//** ReportCommand

ReportCommand::ReportCommand(ToyRobotGameView& _view, ToyRobot& _toyRobot)
	: view(_view)
	, toyRobot(_toyRobot)
{
}

bool ReportCommand::execute(const std::string& arguments)
{
	if (!arguments.empty()) return false;

	view.report(toyRobot.getPosition());
	return true;
}
