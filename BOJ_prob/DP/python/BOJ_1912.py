#*
import sys
length = int(sys.stdin.readline())
num_list = list(map(int, sys.stdin.readline().split()))
dp_list = [0 for i in range(length)]
temp_sum = [0 for i in range(length)]
dp_list[0] = num_list[0]
temp_sum[0] = num_list[0]
for i in range(1, length):
    dp_list[i] = max(dp_list[i -1] + num_list[i], num_list[ i])
print(max(dp_list))