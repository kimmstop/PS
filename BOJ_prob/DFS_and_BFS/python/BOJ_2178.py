import sys
from collections import deque


def isInBound(r, c):
    if r >= 0 and c >= 0 and r < h and c < w:
        return True
    return False

def BFS(r, c):
    queue = deque([(r, c)])
    while queue:
        cur_r, cur_c = queue.popleft()
        for i in range(4):
            next_r = cur_r + dir_r[i]
            next_c = cur_c + dir_c[i]
            if isInBound(next_r, next_c) and miro[next_r][next_c] > 0 and visit[next_r][next_c] == 0:
                visit[next_r][next_c] = 1
                queue.append((next_r, next_c))
                miro[next_r][next_c] = miro[cur_r][cur_c] + 1 


h, w = map(int, sys.stdin.readline().split())
end_r = h - 1
end_c = w - 1
miro = []
for i in range(h):
    miro.append(list(map(int, sys.stdin.readline().rstrip())))
dir_r = [0, 1, 0, -1]
dir_c = [1, 0, -1, 0]
visit = [[0 for j in range(w)] for i in range(h)]
BFS(0, 0)
print(miro[end_r][end_c])