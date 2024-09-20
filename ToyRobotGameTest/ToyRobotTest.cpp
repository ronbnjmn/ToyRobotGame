#include "pch.h"

#include "../ToyRobotGame/ToyRobot.h"

TEST(ToyRobotTest, TestPlace) {
	ToyRobot toyRobot;

	toyRobot.place(Position2d{ 0, 0, Position2d::Direction::NORTH });
	EXPECT_EQ(0, toyRobot.getPosition().x);
	EXPECT_EQ(0, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::NORTH, toyRobot.getPosition().direction);

	toyRobot.place(Position2d{ INT_MAX, INT_MIN, Position2d::Direction::EAST });
	EXPECT_EQ(INT_MAX, toyRobot.getPosition().x);
	EXPECT_EQ(INT_MIN, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::EAST, toyRobot.getPosition().direction);

	toyRobot.place(Position2d{ INT_MIN, INT_MAX, Position2d::Direction::WEST });
	EXPECT_EQ(INT_MIN, toyRobot.getPosition().x);
	EXPECT_EQ(INT_MAX, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::WEST, toyRobot.getPosition().direction);

	toyRobot.place(Position2d{ -1234, 4321, Position2d::Direction::SOUTH });
	EXPECT_EQ(-1234, toyRobot.getPosition().x);
	EXPECT_EQ(4321, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::SOUTH, toyRobot.getPosition().direction);
}

TEST(ToyRobotTest, TestPlaceOutOfBounds) {
	ToyRobot toyRobot(Map2d{ -123, 456, 789, 2345 });
	toyRobot.place(Position2d{ 0, 567, Position2d::Direction::NORTH });

	toyRobot.place(Position2d{ -130, 500, Position2d::Direction::WEST });
	EXPECT_EQ(0, toyRobot.getPosition().x);
	EXPECT_EQ(567, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::NORTH, toyRobot.getPosition().direction);

	toyRobot.place(Position2d{ 123, 450, Position2d::Direction::EAST });
	EXPECT_EQ(0, toyRobot.getPosition().x);
	EXPECT_EQ(567, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::NORTH, toyRobot.getPosition().direction);

	toyRobot.place(Position2d{ 790, 500, Position2d::Direction::WEST });
	EXPECT_EQ(0, toyRobot.getPosition().x);
	EXPECT_EQ(567, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::NORTH, toyRobot.getPosition().direction);

	toyRobot.place(Position2d{ 123, 2350, Position2d::Direction::EAST });
	EXPECT_EQ(0, toyRobot.getPosition().x);
	EXPECT_EQ(567, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::NORTH, toyRobot.getPosition().direction);
}

TEST(ToyRobotTest, TestMoveNorth) {
	ToyRobot toyRobot;
	toyRobot.place(Position2d{ 234, 345, Position2d::Direction::NORTH });

	toyRobot.move();
	EXPECT_EQ(234, toyRobot.getPosition().x);
	EXPECT_EQ(346, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::NORTH, toyRobot.getPosition().direction);

	toyRobot.move();
	EXPECT_EQ(234, toyRobot.getPosition().x);
	EXPECT_EQ(347, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::NORTH, toyRobot.getPosition().direction);
}

TEST(ToyRobotTest, TestMoveWest) {
	ToyRobot toyRobot;
	toyRobot.place(Position2d{ 234, 345, Position2d::Direction::WEST });

	toyRobot.move();
	EXPECT_EQ(233, toyRobot.getPosition().x);
	EXPECT_EQ(345, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::WEST, toyRobot.getPosition().direction);

	toyRobot.move();
	EXPECT_EQ(232, toyRobot.getPosition().x);
	EXPECT_EQ(345, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::WEST, toyRobot.getPosition().direction);
}

TEST(ToyRobotTest, TestMoveSouth) {
	ToyRobot toyRobot;
	toyRobot.place(Position2d{ 234, 345, Position2d::Direction::SOUTH });

	toyRobot.move();
	EXPECT_EQ(234, toyRobot.getPosition().x);
	EXPECT_EQ(344, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::SOUTH, toyRobot.getPosition().direction);

	toyRobot.move();
	EXPECT_EQ(234, toyRobot.getPosition().x);
	EXPECT_EQ(343, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::SOUTH, toyRobot.getPosition().direction);
}

TEST(ToyRobotTest, TestMoveEast) {
	ToyRobot toyRobot;
	toyRobot.place(Position2d{ 234, 345, Position2d::Direction::EAST });

	toyRobot.move();
	EXPECT_EQ(235, toyRobot.getPosition().x);
	EXPECT_EQ(345, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::EAST, toyRobot.getPosition().direction);

	toyRobot.move();
	EXPECT_EQ(236, toyRobot.getPosition().x);
	EXPECT_EQ(345, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::EAST, toyRobot.getPosition().direction);
}

TEST(ToyRobotTest, TestMoveNorthOutOfBounds) {
	ToyRobot toyRobot(Map2d{ -678, -567, 567, 678 });
	toyRobot.place(Position2d{ 123, 678, Position2d::Direction::NORTH });

	toyRobot.move();
	EXPECT_EQ(123, toyRobot.getPosition().x);
	EXPECT_EQ(678, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::NORTH, toyRobot.getPosition().direction);
}

TEST(ToyRobotTest, TestMoveWestOutOfBounds) {
	ToyRobot toyRobot(Map2d{ -678, -567, 567, 678 });
	toyRobot.place(Position2d{ -678, 123, Position2d::Direction::WEST });

	toyRobot.move();
	EXPECT_EQ(-678, toyRobot.getPosition().x);
	EXPECT_EQ(123, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::WEST, toyRobot.getPosition().direction);
}

TEST(ToyRobotTest, TestMoveSouthOutOfBounds) {
	ToyRobot toyRobot(Map2d{ -678, -567, 567, 678 });
	toyRobot.place(Position2d{ 123, -567, Position2d::Direction::SOUTH });

	toyRobot.move();
	EXPECT_EQ(123, toyRobot.getPosition().x);
	EXPECT_EQ(-567, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::SOUTH, toyRobot.getPosition().direction);
}

TEST(ToyRobotTest, TestMoveEastOutOfBounds) {
	ToyRobot toyRobot(Map2d{ -678, -567, 567, 678 });
	toyRobot.place(Position2d{ 567, 600, Position2d::Direction::EAST });

	toyRobot.move();
	EXPECT_EQ(567, toyRobot.getPosition().x);
	EXPECT_EQ(600, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::EAST, toyRobot.getPosition().direction);
}

TEST(ToyRobotTest, TestLeft) {
	ToyRobot toyRobot;
	toyRobot.place(Position2d{ 123, 890, Position2d::Direction::NORTH });

	toyRobot.left();
	EXPECT_EQ(123, toyRobot.getPosition().x);
	EXPECT_EQ(890, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::WEST, toyRobot.getPosition().direction);

	toyRobot.left();
	EXPECT_EQ(123, toyRobot.getPosition().x);
	EXPECT_EQ(890, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::SOUTH, toyRobot.getPosition().direction);

	toyRobot.left();
	EXPECT_EQ(123, toyRobot.getPosition().x);
	EXPECT_EQ(890, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::EAST, toyRobot.getPosition().direction);

	toyRobot.left();
	EXPECT_EQ(123, toyRobot.getPosition().x);
	EXPECT_EQ(890, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::NORTH, toyRobot.getPosition().direction);
}

TEST(ToyRobotTest, TestRight) {
	ToyRobot toyRobot;
	toyRobot.place(Position2d{ 234, 678, Position2d::Direction::NORTH });

	toyRobot.right();
	EXPECT_EQ(234, toyRobot.getPosition().x);
	EXPECT_EQ(678, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::EAST, toyRobot.getPosition().direction);

	toyRobot.right();
	EXPECT_EQ(234, toyRobot.getPosition().x);
	EXPECT_EQ(678, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::SOUTH, toyRobot.getPosition().direction);

	toyRobot.right();
	EXPECT_EQ(234, toyRobot.getPosition().x);
	EXPECT_EQ(678, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::WEST, toyRobot.getPosition().direction);

	toyRobot.right();
	EXPECT_EQ(234, toyRobot.getPosition().x);
	EXPECT_EQ(678, toyRobot.getPosition().y);
	EXPECT_EQ(Position2d::Direction::NORTH, toyRobot.getPosition().direction);
}
