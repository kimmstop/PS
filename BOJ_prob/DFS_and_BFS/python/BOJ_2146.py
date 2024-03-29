#*
import sys
from collections import deque

def isInBound(r, c):
    if r >= 0 and c >= 0 and r < mapsize and c < mapsize:
        return True
    return False


def BFS(r, c):
    island = []
    visit[r][c] = 1
    queue = deque([(r, c)])
    while queue:
        cur_r, cur_c = queue.popleft()
        for i in range(4):
            nr = cur_r + dir_r[i]
            nc = cur_c + dir_c[i] 
            if isInBound(nr, nc) and visit[nr][nc] == 0 and mapinfo[nr][nc] == 1:
                visit[nr][nc] = 1
                mapinfo[nr][nc] = islandID
                queue.append((nr, nc))

def BFS2(cur_islandID):
    global min_dist
    queue = deque([])
    dist = [[0 for j in range(mapsize)] for i in range(mapsize)]
    for i in range(mapsize):
        for j in range(mapsize):
            if mapinfo[i][j] == cur_islandID:
                queue.append((i, j))
                dist[i][j] = 0
    while queue:
        cur_r, cur_c = queue.popleft()
        for i in range(4):
            nr = cur_r + dir_r[i]
            nc = cur_c + dir_c[i]
            if isInBound(nr, nc):
                if mapinfo[nr][nc] > 0 and mapinfo[nr][nc] != cur_islandID:
                    min_dist = min(min_dist, dist[cur_r][cur_c])
                    return
                if mapinfo[nr][nc] == 0 and dist[nr][nc] == 0:
                    dist[nr][nc] = dist[cur_r][cur_c] + 1
                    queue.append((nr, nc))




mapsize = int(sys.stdin.readline())
mapinfo = []
for i in range(mapsize):
    mapinfo.append(list(map(int, sys.stdin.readline().split())))
dir_r = [0, 1, 0, -1]
dir_c = [1, 0, -1, 0]
visit = [[0 for j in range(mapsize)] for i in range(mapsize)]
islandID = 1
for i in range(mapsize):
    for j in range(mapsize):
        if visit[i][j] == 0 and mapinfo[i][j] == 1:
            mapinfo[i][j] = islandID
            BFS(i, j)
            islandID += 1
min_dist = 987654321
for i in range(1, islandID + 1):
    BFS2(i)
print(min_dist)
