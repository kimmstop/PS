#*
import sys
testcasenum = int(sys.stdin.readline())
while testcasenum != 0:
    rowlen = int(sys.stdin.readline())
    dp_list = [[0 for j in range(1)] for i in range(2)]
    dp_list[0] = list(map(int, sys.stdin.readline().split()))
    dp_list[1] = list(map(int, sys.stdin.readline().split()))
    dp_list[0].insert(0,0)
    dp_list[1].insert(0,0)
    for i in range(2, rowlen + 1):
        dp_list[0][i] = max(dp_list[1][i - 1], dp_list[1][i - 2]) + dp_list[0][i]
        dp_list[1][i] = max(dp_list[0][i - 1], dp_list[0][i - 2]) + dp_list[1][i]
    print(max(dp_list[0][rowlen], dp_list[1][rowlen]))
    testcasenum-=1
    
        