import sys
from collections import deque

def isInBound(r, c):
    if r >= 0 and c >= 0 and r < h and c < w:
        return True
    return False


def affectAdjloc(r, c):
    dir_r = [1, 0, -1, 0]
    dir_c = [0, 1, 0, -1]
    for i in range(4):
        next_r = r + dir_r[i]
        next_c = c + dir_c[i] 
        if isInBound(next_r, next_c) and box[next_r][next_c] == 0:
            box[next_r][next_c] = 1
            queue.append((next_r, next_c))
            
def isNotRipe():
    for i in range(h):
        for j in range(w):
            if box[i][j] == 0:
                return True
    return False

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
while queue:
    onedayqueuelen = len(queue)
    for i in range(onedayqueuelen):
        cur_r, cur_c = queue.popleft()
        affectAdjloc(cur_r, cur_c)
    
    if len(queue) == 0:
        break
    dayforripe += 1
if isNotRipe():
    print(-1)
else:    
    print(dayforripe)