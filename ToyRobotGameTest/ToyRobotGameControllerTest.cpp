#include "pch.h"

#include "../ToyRobotGame/ToyRobotGameController.h"

#include "../ToyRobotGame/ToyRobot.h"
#include "../ToyRobotGame/ToyRobotGameView.h"

class MockToyRobot : public ToyRobot
{
public:
	MOCK_METHOD(bool, place, (const Position2d& pos), ());
	MOCK_METHOD(void, move, (), ());
	MOCK_METHOD(void, left, (), ());
	MOCK_METHOD(void, right, (), ());
};

class MockToyRobotGameView : public ToyRobotGameView
{
public:
	MOCK_METHOD(void, report, (const Position2d& position), (const));
};

using ::testing::_;
using ::testing::Return;

TEST(ToyRobotGameControllerTest, TestPLACE) {
	MockToyRobot toyRobot;
	MockToyRobotGameView view;
	ToyRobotGameController controller(toyRobot, view);

	EXPECT_CALL(toyRobot, place(Position2d{ 123, 234, Position2d::Direction::EAST }))
		.Times(1)
		.WillOnce(Return(true));

	controller.onUserInput("PLACE 123,234,EAST");
}

TEST(ToyRobotGameControllerTest, TestMOVE) {
	MockToyRobot toyRobot;
	MockToyRobotGameView view;
	ToyRobotGameController controller(toyRobot, view);

	EXPECT_CALL(toyRobot, place(Position2d{ 123, 234, Position2d::Direction::EAST }))
		.Times(1)
		.WillOnce(Return(true));

	EXPECT_CALL(toyRobot, move())
		.Times(1);

	controller.onUserInput("PLACE 123,234,EAST");
	controller.onUserInput("MOVE");
}

TEST(ToyRobotGameControllerTest, TestLEFT) {
	MockToyRobot toyRobot;
	MockToyRobotGameView view;
	ToyRobotGameController controller(toyRobot, view);

	EXPECT_CALL(toyRobot, place(Position2d{ 123, 234, Position2d::Direction::EAST }))
		.Times(1)
		.WillOnce(Return(true));

	EXPECT_CALL(toyRobot, left())
		.Times(1);

	controller.onUserInput("PLACE 123,234,EAST");
	controller.onUserInput("LEFT");
}

TEST(ToyRobotGameControllerTest, TestRIGHT) {
	MockToyRobot toyRobot;
	MockToyRobotGameView view;
	ToyRobotGameController controller(toyRobot, view);

	EXPECT_CALL(toyRobot, place(Position2d{ 123, 234, Position2d::Direction::EAST }))
		.Times(1)
		.WillOnce(Return(true));

	EXPECT_CALL(toyRobot, right())
		.Times(1);

	controller.onUserInput("PLACE 123,234,EAST");
	controller.onUserInput("RIGHT");
}

TEST(ToyRobotGameControllerTest, TestREPORT) {
	MockToyRobot toyRobot;
	MockToyRobotGameView view;
	ToyRobotGameController controller(toyRobot, view);

	EXPECT_CALL(toyRobot, place(Position2d{ 123, 234, Position2d::Direction::EAST }))
		.Times(1)
		.WillOnce(Return(true));

	EXPECT_CALL(view, report(_))
		.Times(1);

	controller.onUserInput("PLACE 123,234,EAST");
	controller.onUserInput("REPORT");
}

TEST(ToyRobotGameControllerTest, TestIgnoreCommandsBeforePLACE) {
	MockToyRobot toyRobot;
	MockToyRobotGameView view;
	ToyRobotGameController controller(toyRobot, view);

	EXPECT_CALL(toyRobot, move())
		.Times(0);

	EXPECT_CALL(toyRobot, left())
		.Times(0);

	EXPECT_CALL(toyRobot, right())
		.Times(0);

	EXPECT_CALL(view, report(_))
		.Times(0);

	controller.onUserInput("MOVE");
	controller.onUserInput("LEFT");
	controller.onUserInput("RIGHT");
	controller.onUserInput("REPORT");
}


TEST(ToyRobotGameControllerTest, TestIgnoreInvalidArguments) {
	MockToyRobot toyRobot;
	MockToyRobotGameView view;
	ToyRobotGameController controller(toyRobot, view);

	EXPECT_CALL(toyRobot, place(_))
		.Times(0);

	EXPECT_CALL(toyRobot, move())
		.Times(0);

	EXPECT_CALL(toyRobot, left())
		.Times(0);

	EXPECT_CALL(toyRobot, right())
		.Times(0);

	EXPECT_CALL(view, report(_))
		.Times(0);

	controller.onUserInput("NOT_A_COMMAND");
	controller.onUserInput("ANOTHER_NOT_A_COMMAND");
	controller.onUserInput("GOOD DAY!");
}

TEST(ToyRobotGameControllerTest, TestIgnoreInvalidCommands) {
	MockToyRobot toyRobot;
	MockToyRobotGameView view;
	ToyRobotGameController controller(toyRobot, view);

	EXPECT_CALL(toyRobot, place(_))
		.Times(0);

	EXPECT_CALL(toyRobot, move())
		.Times(0);

	EXPECT_CALL(toyRobot, left())
		.Times(0);

	EXPECT_CALL(toyRobot, right())
		.Times(0);

	EXPECT_CALL(view, report(_))
		.Times(0);

	controller.onUserInput("PLACE a,456,SOUTH");
	controller.onUserInput("PLACE 123,b,NORTH");
	controller.onUserInput("PLACE 123,456,THERE");
	controller.onUserInput("PLACE 123");
	controller.onUserInput("PLACE 123,456");
	controller.onUserInput("PLACE 123,456,678,9");
	controller.onUserInput("MOVE a");
	controller.onUserInput("LEFT 1");
	controller.onUserInput("RIGHT !");
	controller.onUserInput("REPORT _");
}
