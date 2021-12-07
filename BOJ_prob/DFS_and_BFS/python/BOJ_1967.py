import sys
sys.setrecursionlimit(10 ** 6)
def DFS(cur_dist):
    global max_dist
    global max_dist_vertex
    cur_vertex = stack.pop()
    visit[cur_vertex] = 1
    for i in adj_list[cur_vertex]:
        next_vertex, dist = i
        if visit[next_vertex] == 0:
            stack.append(next_vertex)
            max_dist = max(DFS(cur_dist + dist), max_dist)
    if cur_dist > max_dist:
        max_dist_vertex = cur_vertex
        max_dist = cur_dist
    return max_dist

vertex_num = int(sys.stdin.readline())
adj_list = [[] for _ in range(vertex_num + 1)]
for _ in range(vertex_num - 1):
    edgeinfo = list(map(int, sys.stdin.readline().split()))
    adj_list[edgeinfo[0]].append((edgeinfo[1], edgeinfo[2]))
    adj_list[edgeinfo[1]].append((edgeinfo[0], edgeinfo[2]))
visit = [0] * (vertex_num + 1)
stack = []
stack.append(1)
max_dist_vertex = 0
max_dist = 0
DFS(0)
stack.append(max_dist_vertex)
visit = [0] * (vertex_num + 1)
DFS(0)
print(max_dist)
    