#*
import sys
length = int(sys.stdin.readline())
num_list = list(map(int, sys.stdin.readline().split()))
dp_list = [0 for i in range(length)]

for i in range(length):
    for j in range(i + 1):
        if num_list[j] < num_list[i] and dp_list[j] > dp_list[i]:
            dp_list[i] = dp_list[j]
    dp_list[i] += num_list[i]
print(max(dp_list))