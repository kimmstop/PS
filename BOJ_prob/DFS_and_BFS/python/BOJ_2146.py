import sys
from collections import deque

def isInBound(r, c):
    if r >= 0 and c >= 0 and r < mapsize and c < mapsize:
        return True
    return False


def BFS(r, c):
    island = []
    visit[r][c] = 1
    island.append((r, c))
    queue = deque([(r, c)])
    while queue:
        cur_r, cur_c = queue.popleft()
        for i in range(4):
            nr = cur_r + dir_r[i]
            nc = cur_c + dir_c[i] 
            if isInBound(nr, nc) and visit[nr][nc] == 0 and mapinfo[nr][nc] == 1:
                visit[nr][nc] = 1
                queue.append((nr, nc))
                island.append((nr, nc))
    islands.append(island)


mapsize = int(sys.stdin.readline())
mapinfo = []
for i in range(mapsize):
    mapinfo.append(list(map(int, sys.stdin.readline().split())))
islands = []
dir_r = [0, 1, 0, -1]
dir_c = [1, 0, -1, 0]
visit = [[0 for j in range(mapsize)] for i in range(mapsize)]
for i in range(mapsize):
    for j in range(mapsize):
        if visit[i][j] == 0 and mapinfo[i][j] == 1:
            BFS(i, j)
islandsnum = len(islands) 
