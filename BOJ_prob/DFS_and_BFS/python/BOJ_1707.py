#*
import sys
from collections import deque
visit = [0] * 20001
stack = []
result = []
def BFS(start_vertex, adj_list):
    queue = deque([start_vertex])
    while queue:
        cur_vertex = queue.popleft()
        for next_vertex in adj_list[cur_vertex]:
            if visit[next_vertex] == 0:
                queue.append(next_vertex)
                if visit[cur_vertex] == 1:
                    visit[next_vertex] = 2
                else:
                    visit[next_vertex] = 1
        
def check_bipartite(adj_list):
    for i in range(1, vertex_num + 1):
        for j in range(len(adj_list[i])):
            if visit[i] == visit[adj_list[i][j]]:
                return False
    return True

testcasenum = int(sys.stdin.readline())
while testcasenum != 0:
    testcasenum -= 1
    vertex_num, edge_num = map(int, sys.stdin.readline().split())
    adj_list = [[] for i in range(vertex_num + 1)]
    for i in range(edge_num):
        v1, v2 = map(int, sys.stdin.readline().split())
        adj_list[v1].append(v2)
        adj_list[v2].append(v1)
    for i in range(1, vertex_num + 1):
        if visit[i] == 0:
            visit[i] = 1
            stack.append(i)
            BFS(i, adj_list)
    if check_bipartite(adj_list) == False:
        result.append("NO")
    else:
        result.append("YES")
    visit = [0] * 20001
print("\n".join(result))
        
    
    
    