import sys
from collections import deque

def isInBound(r, c):
    if r >= 0 and c >= 0 and r < h and c < w:
        return True
    return False

def isLand(r, c):
    if landmap[r][c] == 1:
        return True 
    return False

def BFS(r, c):
    landmap[r][c] = 0
    queue = deque([(r, c)])
    dir_r = [-1, -1, 0, 1, 1, 1, 0, -1]
    dir_c = [0, 1, 1, 1, 0, -1, -1, -1]
    while queue:
        cur_r, cur_c = queue.popleft()
        for i in range(8):
            next_r = cur_r + dir_r[i]
            next_c = cur_c + dir_c[i]
            if isInBound(next_r, next_c):
                if isLand(next_r, next_c):
                    queue.append((next_r, next_c))
                    landmap[next_r][next_c] = 0
                
while True:
    w, h = map(int, sys.stdin.readline().split())
    if w == 0 and h == 0:
      break
    landmap = [[] for i in range(h)]
    for i in range(h):
        landmap[i] = list(map(int, sys.stdin.readline().split()))
    land_count = 0
    for i in range(h):
        for j in range(w):
            if landmap[i][j] == 1:
                BFS(i, j)
                land_count += 1
    print(land_count)
                
                