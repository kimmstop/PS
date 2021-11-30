import sys
sys.setrecursionlimit(10 ** 6)
def DFS(start_vertex, color):
    visit[start_vertex] = color
    for next_vertex in adj_list[start_vertex]:
        if visit[next_vertex] == 0:
            if DFS(next_vertex, -color) == False:
                return False
        elif visit[next_vertex] == visit[start_vertex]:
            return False
    return True


testcasenum = int(sys.stdin.readline())
while testcasenum != 0:
    testcasenum -= 1
    vertex_num, edge_num = map(int, sys.stdin.readline().split())
    visit = [0] * 20001
    adj_list = [[] for i in range(vertex_num + 1)]
    isnotbipartite = 0
    for i in range(edge_num):
        v1, v2 = map(int, sys.stdin.readline().split())
        adj_list[v1].append(v2)
        adj_list[v2].append(v1)
    for i in range(1, vertex_num + 1):
        if visit[i] == 0:
            if DFS(i, 1) == False:
                isnotbipartite = 1
                break
    print("YES"if  not isnotbipartite else "NO") 