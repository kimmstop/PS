import sys
first_arr_size, second_arr_size = map(int, sys.stdin.readline().split())
first_arr = list(map(int, sys.stdin.readline().split()))
second_arr = list(map(int, sys.stdin.readline().split()))
result_arr = sorted(first_arr + second_arr)
for i in result_arr:
    print(i, end = ' ')