import sys
year = list(map(int, sys.stdin.readline().split()))
yearval = [15, 28, 19]
def issame():
    if year[0] == year[1] and year[1] == year[2]:
        return True
    return False

def getmin():
    minval = 987654321
    minidx = 0
    for i in range(3):
        if year[i] < minval:
            minval = year[i]
            minidx = i
    return minidx

while not issame():
    minidx = getmin()
    year[minidx] += yearval[minidx]
print(year[0])
