import sys
from collections import deque
vertex_num, edge_num, start_vertex = map(int, sys.stdin.readline().split())
visit = [0 for i in range(vertex_num + 1)]
adj_list = [[0 for j in range(vertex_num + 1)] for i in range(vertex_num + 1)]
stack = []
def DFS(start_vertex):
    print(start_vertex, end = ' ')
    visit[start_vertex] = 1
    for next_vertex in range(1, len(adj_list[start_vertex])):
        if visit[next_vertex] == 0 and adj_list[start_vertex][next_vertex] == 1:
            stack.append(next_vertex)
            DFS(next_vertex)
    stack.pop()
    
def BFS(start_vertex):
   visit[start_vertex] = 1
   q = deque([start_vertex])
   while q:
       cur_vertex = q.popleft()
       print(cur_vertex, end = ' ')
       for i in range(1, len(adj_list[cur_vertex])):
           if visit[i] == 0 and adj_list[cur_vertex][i] == 1:
               q.append(i)
               visit[i] = 1
            

for i in range(edge_num):
    v1, v2 = map(int, sys.stdin.readline().split())
    adj_list[v1][v2] = 1
    adj_list[v2][v1] = 1
stack.append(start_vertex)
visit[start_vertex] = 1
DFS(start_vertex)
print('')
visit = [0] * (vertex_num+1)
BFS(start_vertex)