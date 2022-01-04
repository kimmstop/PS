import sys

numofpeople = int(sys.stdin.readline())
timetowithdraw = list(map(int, sys.stdin.readline().split()))
timetowithdraw.sort()
totaltime = 0
waittime = 0
for i in timetowithdraw:
    totaltime = totaltime + waittime + i
    waittime += i
print(totaltime)
