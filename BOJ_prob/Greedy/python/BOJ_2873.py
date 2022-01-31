#*
import sys
from collections import deque
def findMin():
    minvalidx = (0, 0)
    minval = 1000
    global r, c
    for i in range(r):
        for j in range(c):
            if not (i == 0 and j == 0) and not (i == r -1 and j == c -1):
                if (i % 2 == 0 and j % 2 != 0) or (i % 2 != 0 and j % 2 == 0):
                    if groundinfo[i][j] < minval:
                        minval = groundinfo[i][j]
                        minvalidx = (i, j)
    return minvalidx

def inRange(cur_r, cur_c):
    if 0 <= cur_r < r and 0 <= cur_c < c:
        return True
    return False


def getPath0(minr, minc):
    global r, c
    path.append(('D' * (r -1) + 'R' + 'U' * (r - 1) + 'R') * (minc//2))
    cur_r, cur_c = 0, 2 * (minc//2)
    cbound = cur_c + 1
    while not (cur_c == cbound and cur_r == r -1):
        if cur_c < cbound and [cur_r, cur_c + 1] != [minr, minc]:
            path.append('R')
            cur_c += 1
        elif cur_c == cbound  and [cur_r, cur_c - 1] != [minr, minc]:
            path.append('L')
            cur_c -= 1
        if cur_r + 1 <= r - 1:
            path.append('D')
            cur_r += 1
    path.append(('R' + 'U' * (r - 1) + 'R' + 'D' * (r - 1)) * ((c - minc - 1) // 2))
def getPath1():
    global r, c
    for i in range(c):
        if i % 2 == 0:
            path.append('D' * (r - 1))
            if i != c - 1:
                path.append('R')
        else:
            path.append('U' * (r - 1))
            path.append('R')

def getPath2():
    global r, c
    for i in range(r):
        if i % 2 == 0:
            path.append('R' * (c - 1))
            if i != r - 1:
                path.append('D')
        else:
            path.append('L' * (c - 1))
            path.append('D')

r, c = map(int, sys.stdin.readline().split())
groundinfo = []
path = []
for i in range(r):
    groundinfo.append(list(map(int, sys.stdin.readline().split())))
if r % 2 == 0 and c % 2 == 0:
    minr, minc = findMin()
    groundinfo[minr][minc] = 0
    getPath0(minr, minc)
elif c % 2 != 0 and r % 2 == 0:
    getPath1()
else:
    getPath2()
for i in path:
    print(i, end='')