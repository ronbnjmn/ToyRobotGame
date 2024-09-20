#include "ToyRobot.h"
#include "ToyRobotGameController.h"
#include "ToyRobotGameUI.h"

int main()
{
	ToyRobotGameUI ui;
	ToyRobot toyRobot(Map2d{ 0, 0, 5, 5 });
	ToyRobotGameController controller(toyRobot, ui);
	ui.setInputHandler(controller);

	while (ui.receiveInput() != "QUIT");

	return 0;
}
