import sys

numofloc = int(sys.stdin.readline())
locarr = [[0 for j in range(2)] for i in range(numofloc)]
for i in range(numofloc):
    x, y = map(int,(sys.stdin.readline().split()))
    locarr[i] = [x, y]

locarr.sort()

for i in range(numofloc):
    print(locarr[i][0], locarr[i][1])
    
