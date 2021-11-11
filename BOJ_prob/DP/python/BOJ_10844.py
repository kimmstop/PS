#*
import sys
num = int(sys.stdin.readline())
dp_list = [[0 for j in range(10)] for i in range(101)]
for i in range(1, 10):
    dp_list[1][i] = 1
for i in range(2, 101):
    for j in range(0, 10):
        if j == 0:
            dp_list[i][j] = dp_list[i -1][j +1]
        elif j == 9:
            dp_list[i][j] = dp_list[i - 1][j -1]
        else:
            dp_list[i][j] = dp_list[i - 1][j -1] + dp_list[i -1][j +1]
print(sum(dp_list[num]) %  1000000000)