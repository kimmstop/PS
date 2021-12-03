import sys

def calNextNum(num):
    num = list(str(num))
    nextNum = 0
    for i in range(len(num)):
        nextNum += int(num[i]) ** P
    return nextNum

A, P = map(int, sys.stdin.readline().split())
visit = [0] * 15000000
curNum = A
visit[curNum] = 1
numlist = []
numlist.append(curNum)
while True:
    nextNum = calNextNum(curNum)
    if visit[nextNum] == 0:
        visit[nextNum] = 1
        numlist.append(nextNum)
        curNum = nextNum
    else:
        print(numlist.index(nextNum))
        break

