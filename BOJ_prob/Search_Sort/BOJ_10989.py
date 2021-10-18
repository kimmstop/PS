import sys

numcount = int(sys.stdin.readline())
radixarr = [0 for i in range(10001)]
for i in range(numcount):
    num = int(sys.stdin.readline())
    radixarr[num] += 1
for i in range(10001):
    for j in range(radixarr[i]):
        print(i)
