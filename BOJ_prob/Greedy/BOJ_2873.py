import sys
from collections import deque
def findMin():
    minvalidx = (0, 0)
    minval = 1000
    global r, c
    for i in range(r):
        for j in range(c):
            if not (i == 0 and j == 0) and not (i == r -1 and j == c -1):
                if not (i % 2 == 0 and j % 2 == 0 ):
                    if groundinfo[i][j] < minval:
                        minval = groundinfo[i][j]
                        minvalidx = (i, j)
    return minvalidx

def inRange(next_r, next_c):
    global r, c
    if 0 <= next_r < r and 0 <= next_c < c:
        return True
    return False

def BFS():
    queue = deque([(0, 0)])
    groundinfo[0][0] = 0
    dir_r = [1, 0, -1, 0]
    dir_c = [0, 1, 0, -1]
    dir = ['D', 'R', 'U', 'L']
    while queue:
        cur_r, cur_c = queue.popleft()
        for i in range(4):
            next_r = cur_r + dir_r[i]
            next_c = cur_c + dir_c[i]
            if inRange(next_r, next_c) and groundinfo[next_r][next_c] != 0:
                path.append(dir[i])
                queue.append((next_r, next_c))
                groundinfo[next_r][next_c] = 0

def getPath1():
    global r, c
    for i in range(r):
        if i % 2 == 0:
            path.append('D' * (c - 1))
            if i != r - 1:
                path.append('R')
        else:
            path.append('U' * (c - 1))
            path.append('R')

def getPath2():
    global r, c
    for i in range(c):
        if i % 2 == 0:
            path.append('R' * (r - 1))
            if i != r - 1:
                path.append('D')
        else:
            path.append('L' * (r - 1))
            path.append('D')

r, c = map(int, sys.stdin.readline().split())
groundinfo = []
path = []
for i in range(c):
    groundinfo.append(list(map(int, sys.stdin.readline().split())))
if r % 2 == 0 and c % 2 == 0:
    minr, minc = findMin()
    groundinfo[minr][minc] = 0
    BFS()
elif r % 2 != 0 and c % 2 == 0:
    getPath1()
else:
    getPath2()
for i in path:
    print(i, end='')