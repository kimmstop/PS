import sys
sys.setrecursionlimit(10 ** 6)
def DFS(start_vertex):
    visit[start_vertex] = 1
    #print(start_vertex, end = ' ')
    for i in adj_list[start_vertex]:
        next_vertex = i
        if visit[next_vertex] == 0:
            visit[next_vertex] = 1
            stack.append(next_vertex)
            DFS(next_vertex)
    if len(stack) == 0:
        return
    stack.pop()


testcasenum = int(sys.stdin.readline())
while testcasenum != 0:
    testcasenum -= 1
    permu_size = int(sys.stdin.readline())
    adj_list = [[] for i in range(permu_size + 1)]
    permu = list(map(int, sys.stdin.readline().split()))
    permu.insert(0, 0)
    permu_count = 0
    stack = []
    visit = [0] * (permu_size + 1)
    for i in range(1, permu_size + 1):
        adj_list[i].append(permu[i])
        adj_list[permu[i]].append(i)
    for i in range(1, permu_size + 1):
        if visit[i] == 0:
            DFS(i)
            permu_count +=1
    print(permu_count)