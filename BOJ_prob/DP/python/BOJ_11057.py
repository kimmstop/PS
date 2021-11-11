#*
import sys
lenofnum = int(sys.stdin.readline())
dp_list = [[0 for j in range(10)] for i in range(1001)]
for i in range(10):
    dp_list[1][i] = 1
for i in range(2, lenofnum + 1):
    dp_list[i][0] = 1
    for j in range(1, 10):
        dp_list[i][j] = dp_list[i][j - 1] + dp_list[i -1][j]
sum = 0
for i in range(10):
    sum += dp_list[lenofnum][i]
print(sum % 10007)