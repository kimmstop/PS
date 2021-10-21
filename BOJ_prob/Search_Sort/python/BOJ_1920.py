import bisect

numofarr1 = int(input())
arr1 = input().split()
numofarr2 = int(input())
arr2 = input().split()
is_exist = {}
arr1.sort()
for i in range(numofarr2):
    r = bisect.bisect_left(arr1, arr2[i])
    r = int(r)
    if r != len(arr1) and arr1[r] == arr2[i]:
        print(1)
    else:
        print(0)
