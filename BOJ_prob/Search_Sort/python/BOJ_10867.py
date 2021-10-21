import sys

numofnumarr = int(sys.stdin.readline())
numarr = list(map(int, sys.stdin.readline().split()))
numarr.sort()
for i in range(numofnumarr):
    if i > 0 and numarr[i] == numarr[i - 1]:
        continue;
    print(numarr[i], end=' ')