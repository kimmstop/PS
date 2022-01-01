import sys

def divide(part_arr):
    half = len(part_arr) // 2
    arr1 = part_arr[:half]
    arr2 = part_arr[half:]
    if len(arr1) != 1:
        arr1 = divide(arr1)
    if len(arr2) != 1:
        arr2 = divide(arr2)
    result = merge(arr1, arr2)
    return result


def merge(f_arr, s_arr):
    global num_of_swap
    result = []
    f, s = 0, 0
    while f != len(f_arr) and s != len(s_arr):
        if f_arr[f] > s_arr[s]:
            result.append(s_arr[s])
            s += 1
            num = len(f_arr) - f
            num_of_swap += num
        else:
            result.append(f_arr[f])
            f += 1
    if f == len(f_arr):
        for i in range(s, len(s_arr)):
            result.append(s_arr[i])
    else:
        for i in range(f, len(f_arr)):
            result.append(f_arr[i])
    return result
        
    

arr_size = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
num_of_swap = 0
divide(arr)
print(num_of_swap)