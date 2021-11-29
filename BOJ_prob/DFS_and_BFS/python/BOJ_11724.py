import sys
from collections import deque



def Search(start_vertex):
    visit[start_vertex] = 1
    queue = deque([start_vertex])
    while queue:
        cur_vertex = queue.popleft()
        for next_vertex in adj_list[cur_vertex]:
            if visit[next_vertex] == 0:
                queue.append(next_vertex)
                visit[next_vertex] = 1

vertex_num, edge_num = map(int, sys.stdin.readline().split())
adj_list = [[] for i in range(vertex_num + 1)]
visit = [0] * (vertex_num + 1)
connected_component = 0
for _ in range(edge_num):
    v1, v2 = map(int, sys.stdin.readline().split())
    adj_list[v1].append(v2)
    adj_list[v2].append(v1)
for not_visit_vertex in range(1, vertex_num + 1):
    if visit[not_visit_vertex] == 0:
        Search(not_visit_vertex)
        connected_component += 1
print(connected_component)
