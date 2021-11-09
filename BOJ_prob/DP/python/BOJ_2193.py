import sys
lenofnum = int(sys.stdin.readline())
numofendone = 1
dp_list = [[0 for j in range(2)] for i in range(91)]
dp_list[1][0] = 0
dp_list[1][1] = 1
for i in range(2, lenofnum + 1):
    dp_list[i][0] = dp_list[i - 1][0] + dp_list[i - 1][1]
    dp_list[i][1] = dp_list[i - 1][0]
print(dp_list[lenofnum][0] + dp_list[lenofnum][1])