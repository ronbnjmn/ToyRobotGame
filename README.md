# Toy Robot Game

Toy Robot Game is a console app that simulates a toy robot that you move on a table.

## Building

This project requires Visual Studio 2022 with C++ to build the app.

1. Open the ToyRobotGame.sln solution in Visual Studio.
2. Build the app by choosing `Build`-> `Build Solution` from the menu bar, or pressing `Ctrl+Shift+B`.
3. Run the game by choosing `Debug` -> `Start Without Debugging` from the menu bar, or pressing `Ctrl-F5`.

## Usage

You play the game by moving the toy robot within the table that's 5 units long and 5 units wide. You do that with following commands.

1. The `PLACE X,Y,Direction` command

   Begin by placing the toy robot on the table with the `PLACE` command. This command accepts three parameters separated by a comma. The first two parameters specify the position of the robot relative to the south-west corner of the table which we call the origin, the position of which is `0, 0`. The third parameter specifies the direction the toy robot will face.

   For example, the following command places the toy robot at 1 unit to the east, 2 units to the north of the origin, and facing the north direction, at `1, 2, NORTH`.

   ```
   PLACE 1,2,NORTH
   ```

2. The `MOVE` command

   You can move the toy robot 1 unit to the direction it's facing with the `MOVE` command. For example, calling this command after placing the toy robot at `1, 2, NORTH`, will move the position of the toy robot to `1, 3, NORTH`. 

3. The `LEFT` and `RIGHT` commands

   You can turn the toy robot to face a different direction with the `LEFT` and `RIGHT`commands. The `LEFT` command will turn the robot to its left by 90&deg;, while the `RIGHT` command will turn the robot to its right by 90&deg;.

4. The `REPORT` command

   You can query the exact position of the toy robot with the `REPORT` command.

That's it. You can enjoy the game by moving, placing, or turning the robot in any which way you want. Unfortunately, you can't place the robot outside the table, you can't take it off the table, or let it fall off the table. The game won't let you. If you want to quit the game, enter `QUIT`.

## Testing

### Unit tests

You can run the included unit tests within Test Explorer in Visual Studio. 

1. Open Test Explorer by choosing `Test` -> `Test Explorer` from the menu bar.
2. Run the unit tests by clicking `Run All` or pressing `Ctrl+R, V`.

### Functional test

You can run the included test.py script to test the app functionality. Python 3.12 is required.

1. Open PowerShell and change directory to the project directory.

   ```
   PS> Set-Location <project directory>
   ```
2. Run the python test script

   ```
   PS> python.exe .\test.py
   ```
