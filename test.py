# test.py
# 
# Testing for ToyRobotGame
#

import subprocess

passed = 0
failed = 0

def run_test(test_case, input, expected):
    print('{0}...'.format(test_case))

    proc = subprocess.Popen(["./x64/Debug/ToyRobotGame.exe"], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    output, error = proc.communicate(input.encode())
    output = output.decode('UTF-8')
    proc.terminate()

    # print(output)
    # print(expected)

    if output == expected:
        print('{0} PASSED!'.format(test_case))
        global passed
        passed += 1
    else:
        print('{0} FAILED!'.format(test_case))
        global failed
        failed += 1

def test1():
    test_case = "SeriesOfCommands1"
    input = \
    "PLACE 1,2,EAST\n" \
    "MOVE\n" \
    "MOVE\n" \
    "LEFT\n" \
    "MOVE\n" \
    "REPORT\n" \
    "QUIT\n"
    expected = "OUTPUT: 3,3,NORTH\r\n"
    return test_case, input, expected

def test2():
    test_case = "PLACEShouldBeFirst"
    input = \
    "MOVE\n" \
    "LEFT\n" \
    "RIGHT\n" \
    "REPORT\n" \
    "PLACE 1,1,NORTH\n" \
    "REPORT\n" \
    "QUIT\n"
    expected = "OUTPUT: 1,1,NORTH\r\n"
    return test_case, input, expected

def test3():
    test_case = "NORTHDirection"
    input = \
    "PLACE 1,1,NORTH\n" \
    "MOVE\n" \
    "MOVE\n" \
    "LEFT\n" \
    "RIGHT\n" \
    "LEFT\n" \
    "RIGHT\n" \
    "RIGHT\n" \
    "REPORT\n" \
    "QUIT\n"
    expected = "OUTPUT: 1,3,EAST\r\n"
    return test_case, input, expected

def test4():
    test_case = "EASTDirection"
    input = \
    "PLACE 2,2,EAST\n" \
    "MOVE\n" \
    "MOVE\n" \
    "LEFT\n" \
    "RIGHT\n" \
    "LEFT\n" \
    "RIGHT\n" \
    "RIGHT\n" \
    "REPORT\n" \
    "QUIT\n"
    expected = "OUTPUT: 4,2,SOUTH\r\n"
    return test_case, input, expected

def test5():
    test_case = "WESTDirection"
    input = \
    "PLACE 2,2,WEST\n" \
    "MOVE\n" \
    "MOVE\n" \
    "LEFT\n" \
    "RIGHT\n" \
    "LEFT\n" \
    "RIGHT\n" \
    "RIGHT\n" \
    "REPORT\n" \
    "QUIT\n"
    expected = "OUTPUT: 0,2,NORTH\r\n"
    return test_case, input, expected

def test6():
    test_case = "SOUTHDirection"
    input = \
    "PLACE 2,2,SOUTH\n" \
    "MOVE\n" \
    "MOVE\n" \
    "LEFT\n" \
    "RIGHT\n" \
    "LEFT\n" \
    "RIGHT\n" \
    "RIGHT\n" \
    "REPORT\n" \
    "QUIT\n"
    expected = "OUTPUT: 2,0,WEST\r\n"
    return test_case, input, expected


def test7():
    test_case = "NORTHDirectionOutOfBounds"
    input = \
    "PLACE 2,2,NORTH\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "REPORT\n" \
    "QUIT\n"
    expected = "OUTPUT: 2,5,NORTH\r\n"
    return test_case, input, expected

def test8():
    test_case = "EASTDirectionOutOfBounds"
    input = \
    "PLACE 2,2,EAST\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "REPORT\n" \
    "QUIT\n"
    expected = "OUTPUT: 5,2,EAST\r\n"
    return test_case, input, expected

def test9():
    test_case = "WESTDirectionOutOfBounds"
    input = \
    "PLACE 2,2,WEST\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "REPORT\n" \
    "QUIT\n"
    expected = "OUTPUT: 0,2,WEST\r\n"
    return test_case, input, expected

def test10():
    test_case = "SOUTHDirectionOutOfBounds"
    input = \
    "PLACE 2,2,SOUTH\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "MOVE\n" \
    "REPORT\n" \
    "QUIT\n"
    expected = "OUTPUT: 2,0,SOUTH\r\n"
    return test_case, input, expected

def test11():
    test_case = "PLACEOutOfBounds"
    input = \
    "PLACE -1,2,SOUTH\n" \
    "REPORT\n" \
    "PLACE 6,2,NORTH\n" \
    "REPORT\n" \
    "PLACE 3,-2,WEST\n" \
    "REPORT\n" \
    "PLACE 3,8,EAST\n" \
    "REPORT\n" \
    "PLACE 0,0,SOUTH\n" \
    "REPORT\n" \
    "QUIT\n"
    expected = "OUTPUT: 0,0,SOUTH\r\n"
    return test_case, input, expected


def test12():
    test_case = "InvalidCommandsNoReport"
    input = \
    "INVALID_COMMAND\n" \
    "REPORT\n" \
    "THIS_ONEasd\n" \
    "REPORT\n" \
    "1231231029381290389\n" \
    "REPORT\n" \
    "1230921840938483\n" \
    "REPORT\n" \
    "12380480384923\n" \
    "REPORT\n" \
    "QUIT\n"
    expected = ""
    return test_case, input, expected

def run_all_tests():
    run_test(*test1())
    run_test(*test2())
    run_test(*test3())
    run_test(*test4())
    run_test(*test5())
    run_test(*test6())
    run_test(*test7())
    run_test(*test8())
    run_test(*test9())
    run_test(*test10())
    run_test(*test11())
    run_test(*test12())

run_all_tests()
print()
print('{0} tests PASSED'.format(passed))
print('{0} tests FAILED'.format(failed))
print()
