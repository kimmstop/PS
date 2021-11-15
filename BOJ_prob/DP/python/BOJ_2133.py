#*
import sys
rowlen = int(sys.stdin.readline())
dp_list = [0 for i in range(31)]
dp_list[2] = 3
for i in range(4, rowlen+1, 2):
    dp_list[i] = dp_list[i - 2] * 3
    for j in range(4, i , 2):
        dp_list[i] += 2 * dp_list[i - j]
    dp_list[i] += 2
print(dp_list[rowlen])