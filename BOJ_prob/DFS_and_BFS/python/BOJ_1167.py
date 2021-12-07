import sys
sys.setrecursionlimit(10 ** 6)

def DFS(curdist):
    global maxdist
    global maxdist_vertex
    curvertex = stack.pop()
    for i in adj_list[curvertex]:
        nextvertex, dist = i
        if visit[nextvertex] == 0:
            visit[nextvertex] = 1
            stack.append(nextvertex)
            maxdist = max(DFS(curdist + dist), maxdist)
    if curdist > maxdist:
        maxdist_vertex = curvertex
        maxdist = curdist
    return maxdist
    
vertexnum = int(sys.stdin.readline())
adj_list = [[] for i in range(vertexnum + 1)]
for i in range(1, vertexnum + 1):
    edgeinfo = list(map(int, sys.stdin.readline().split()))
    v1 = edgeinfo[0]
    for j in range(1, len(edgeinfo) - 2, 2):
        adj_list[v1].append((edgeinfo[j], edgeinfo[j + 1]))
maxdist = 0
maxdist_vertex = 0
visit = [0] * (vertexnum + 1)
stack = []
stack.append(1)
visit[1] = 1
DFS(0)
visit = [0] * (vertexnum + 1)
stack.append(maxdist_vertex)
visit[maxdist_vertex] = 1
DFS(0)
print(maxdist)


