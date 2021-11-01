import sys
testcase_num = int(sys.stdin.readline())
for i in range(testcase_num):
    n = int(sys.stdin.readline())
    dp_list = [0] * 11
    dp_list[1] = 1
    dp_list[2] = 2
    dp_list[3] = 4
    dp_list[4] = 7
    for j in range(5, 11):
        dp_list[j] = dp_list[j -1] + dp_list[j - 2] + dp_list[j - 3] 
    print(dp_list[n])