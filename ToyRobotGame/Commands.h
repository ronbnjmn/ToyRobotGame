#pragma once

#include <string>

class ToyRobot;
class ToyRobotGameView;

// Command - class that can perform actions to its receiver
// Subclasses implement the Command interface to perform specific actions on their receivers

//** Command

class Command
{
public:
	virtual ~Command() {};
	virtual bool execute(const std::string& arguments) = 0;
};


//** PlaceCommand

class PlaceCommand
	: public Command
{
public:
	PlaceCommand(ToyRobot& toyRobot);

	bool execute(const std::string& arguments) override;

private:
	ToyRobot& toyRobot;
};


//** MoveCommand

class MoveCommand
	: public Command
{
public:
	MoveCommand(ToyRobot& toyRobot);

	bool execute(const std::string& arguments) override;

private:
	ToyRobot& toyRobot;
};


//** LeftCommand

class LeftCommand
	: public Command
{
public:
	LeftCommand(ToyRobot& toyRobot);

	bool execute(const std::string& arguments) override;

private:
	ToyRobot& toyRobot;
};


//** RightCommand

class RightCommand
	: public Command
{
public:
	RightCommand(ToyRobot& toyRobot);

	bool execute(const std::string& arguments) override;

private:
	ToyRobot& toyRobot;
};


//** ReportCommand

class ReportCommand
	: public Command
{
public:
	ReportCommand(ToyRobotGameView& view, ToyRobot& toyRobot);

	bool execute(const std::string& arguments) override;

private:
	ToyRobotGameView& view;
	ToyRobot& toyRobot;
};
