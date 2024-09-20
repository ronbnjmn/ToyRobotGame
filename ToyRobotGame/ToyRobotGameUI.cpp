#include "ToyRobotGameUI.h"

#include <iostream>
#include "Position2d.h"
#include "ToyRobotGameInputHandler.h"

ToyRobotGameUI::ToyRobotGameUI()
	: handler(nullptr)
{
}

void ToyRobotGameUI::setInputHandler(ToyRobotGameInputHandler& _handler)
{
	handler = &_handler;
}

std::string ToyRobotGameUI::receiveInput()
{
	std::string input;
	std::getline(std::cin, input);
	if (handler != nullptr) handler->onUserInput(input);
	return input;
}

void ToyRobotGameUI::report(const Position2d& position) const
{
	std::cout << "OUTPUT: " << position.x << "," << position.y << "," << position.getDescription() << std::endl;
}
