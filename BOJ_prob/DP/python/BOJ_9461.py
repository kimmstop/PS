import sys
testcase_num = int(sys.stdin.readline())

while testcase_num != 0:
    num = int(sys.stdin.readline())
    dp_list = [0 for i in range(101)]
    dp_list[0] = 1
    dp_list[1] = 1
    dp_list[2] = 1
    dp_list[3] = 2
    dp_list[4] = 2
    for i in range(5, num):
        dp_list[i] = dp_list[i - 5] +dp_list[i -1]
    print(dp_list[num -1])
    testcase_num -= 1