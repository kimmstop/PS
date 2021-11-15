
#*
import sys
num = int(sys.stdin.readline())
num_list = []
for i in range(1, num + 1):
    num_list.append(i * i)
dp_list = [0 for i in range(num + 1)]
index = 0
for i in range(1, num + 1):
    temp_list = []
    for j in range(num + 1):
        if num_list[j] > i:
            break
        temp_list.append(dp_list[i - num_list[j]])
    dp_list[i] = min(temp_list) + 1
print(dp_list[num])