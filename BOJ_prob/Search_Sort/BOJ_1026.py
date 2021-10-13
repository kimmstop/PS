import sys

num_of_arr_ele = int(input())

#arr1 = list(map(int, sys.stdin.readline().split()))
#arr2 = list(map(int, sys.stdin.readline().split()))
arr1 = input().split()
arr2 = input().split()

for i in range(num_of_arr_ele):
    arr1[i] = int(arr1[i])
for i in range(num_of_arr_ele):
    arr2[i] = int(arr2[i])

arr1.sort()
arr2.sort()

sum = 0

for i in range(num_of_arr_ele):
    print(int(arr1[i]), int(arr2[num_of_arr_ele - i - 1]))
    sum += (int(arr1[i]) * int(arr2[num_of_arr_ele - i - 1]))
print(int(sum))