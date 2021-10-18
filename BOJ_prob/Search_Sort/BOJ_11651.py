import sys

numofloc = int(sys.stdin.readline())
locarr = [[0 for j in range(2)] for i in range(numofloc)]
for i in range(numofloc):
    x, y = map(int,(sys.stdin.readline().split()))
    locarr[i] = [y, x]

locarr.sort()

for i in range(numofloc):
    print(locarr[i][1], locarr[i][0])
    
