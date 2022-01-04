import sys

arrsize = int(sys.stdin.readline())
arr = []
for i in range(arrsize):
    arr.append(int(sys.stdin.readline()))
arr.sort()
optarr = []
idx = 0
for i in range(arrsize):
    if idx >= arrsize:
        break
    if idx + 1 <= arrsize - 1 and arr[idx] < 0 and arr[idx + 1] <= 0:
        optarr.append(arr[idx] * arr[idx + 1])
        idx += 1
    elif arr[idx] >= 0:
        break
    else:
        optarr.append(arr[idx])
    idx += 1
idx = arrsize - 1
for i in range(arrsize):
    if idx < 0:
        break
    if idx != 0 and arr[idx] > 1 and arr[idx - 1] > 1:
        optarr.append(arr[idx] * arr[idx - 1])
        idx -= 1
    elif arr[idx] <= 0:
        break
    else:
        optarr.append(arr[idx])
    idx -= 1
print(sum(optarr))