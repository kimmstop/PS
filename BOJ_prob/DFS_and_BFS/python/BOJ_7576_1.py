import sys
from collections import deque

def isInBound(r, c):
    if r >= 0 and c >= 0 and r < h and c < w:
        return True
    return False

def BFS():
    while queue:
        cur_r, cur_c = queue.popleft()
        dir_r = [1, 0, -1, 0]
        dir_c = [0, 1, 0, -1]
        for i in range(4):
            next_r = cur_r + dir_r[i]
            next_c = cur_c + dir_c[i]
            if isInBound(next_r, next_c) and box[next_r][next_c] == 0:
                queue.append((next_r, next_c))
                box[next_r][next_c] = box[cur_r][cur_c] + 1



w, h = map(int, sys.stdin.readline().split())
box = []
visit = [[0 for j in range(w)] for i in range(h)]
for i in range(h):
    box.append(list(map(int, sys.stdin.readline().split())))
dayforripe = 0
queue = deque()
for i in range(h):
    for j in range(w):
        if box[i][j] == 1:
            queue.append((i, j))
BFS()
ans = 0
for i in box:
    for j in i:
        if j == 0:
            print(-1)
            exit(0)
    ans = max(ans, max(i))
print(ans - 1)
