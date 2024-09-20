#include "pch.h"

#include "../ToyRobotGame/ToyRobotGameUI.h"

#include "../ToyRobotGame/Position2d.h"
#include "../ToyRobotGame/ToyRobotGameInputHandler.h"

using ::testing::StrEq;

class MockToyRobotGameInputHandler : public ToyRobotGameInputHandler
{
public:
	MOCK_METHOD(void, onUserInput, (const std::string& input), (override));
};

TEST(ToyRobotGameUITest, TestInput) {
	// Redirect std::cin
	std::istringstream in("PLACE 1,2,NORTH\nLEFT\nREPORT");
	std::streambuf* cinbuf = std::cin.rdbuf();
	std::cin.rdbuf(in.rdbuf());

	MockToyRobotGameInputHandler handler;
	EXPECT_CALL(handler, onUserInput(StrEq("PLACE 1,2,NORTH")))
		.Times(1);

	ToyRobotGameUI ui;
	ui.setInputHandler(handler);
	ui.receiveInput();
}

TEST(ToyRobotGameUITest, TestOutput) {
	// Redirect std::cout
	std::ostringstream out;
	std::streambuf* coutbuf = std::cout.rdbuf();
	std::cout.rdbuf(out.rdbuf());

	ToyRobotGameUI ui;
	ui.report(Position2d{ 123, 987, Position2d::Direction::NORTH });

	EXPECT_EQ("OUTPUT: 123,987,NORTH\n", out.str());
}
