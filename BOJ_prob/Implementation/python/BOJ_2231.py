import sys

def getPartSum(num):
    num2str = list(str(num))
    partsum = num
    for i in num2str:
        partsum += ord(i) - ord('0')
    return partsum



N = int(sys.stdin.readline())
for i in range(1, N + 1):
    if getPartSum(i) == N:
        print(i)
        exit()
print(0)