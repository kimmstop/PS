import sys
length = int(input())
num_list = list(map(int, sys.stdin.readline().split()))
dp_list1 = [0 for i in range(length)]
dp_list2 = [0 for i in range(length)]
dp_list3 = [0 for i in range(length)]
for i in range(length):
    for j in range(i + 1):
            if num_list[j] < num_list[i] and dp_list1[j] > dp_list1[i]:
                dp_list1[i] = dp_list1[j]
    dp_list1[i] += 1

for i in range(length - 1, -1, -1):
    for j in range(length- 1, i - 1, -1):
            if num_list[j] < num_list[i] and dp_list2[j] > dp_list2[i]:
                dp_list2[i] = dp_list2[j]
    dp_list2[i] += 1
   
for i in range(length):
    dp_list3[i] = dp_list1[i] + dp_list2[i]
print(max(dp_list3) - 1)