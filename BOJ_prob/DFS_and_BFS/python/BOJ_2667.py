import sys
from collections import deque

def isInBound(r, c):
    if r >= 0 and c >= 0 and r < aptmapsize and c < aptmapsize:
        return True
    return False

def isConnected(r, c):
    if aptmap[r][c] == 1:
        return True 
    return False

def BFS(r, c):
    visit[r][c] = 1
    partaptnum = 1
    queue = deque([(r, c)])
    dir_r = [-1, 0, 1, 0]
    dir_c = [0, -1, 0, 1]
    while queue:
        cur_r, cur_c = queue.popleft()
        for i in range(4):
            next_r = cur_r + dir_r[i]
            next_c = cur_c + dir_c[i]
            if isInBound(next_r, next_c) and isConnected(next_r, next_c) and visit[next_r][next_c] == 0:
                queue.append((next_r, next_c))
                visit[next_r][next_c] = 1
                partaptnum += 1
    return partaptnum

aptmapsize = int(sys.stdin.readline())
aptmap = [[] for i in range(aptmapsize)]
aptnum = []
visit = [[0 for j in range(aptmapsize)] for i in range(aptmapsize)]
for i in range(aptmapsize):
    aptmap[i] = list(map(int, sys.stdin.readline().rstrip()))
for i in range(aptmapsize):
    for j in range(aptmapsize):
        if visit[i][j] == 0 and aptmap[i][j] == 1:
            aptnum.append(BFS(i, j))
aptnum.sort()
print(len(aptnum))
for i in aptnum:
    print(i)