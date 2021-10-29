import sys
width = int(sys.stdin.readline())
dp_list = [0] * 1001
dp_list[1] = 1
dp_list[2] = 3
for i in range(3, width + 1):
    dp_list[i] = dp_list[i - 1] + 2 * dp_list[i - 2]
print(dp_list[width] % 10007)
