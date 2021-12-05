import sys
sys.setrecursionlimit(10 ** 6)
def findParentNode(c_node):
    for i in adj_list[c_node]:
        if nodeparent[i] == 0:
            nodeparent[i] = c_node
            findParentNode(i)



nodenum = int(sys.stdin.readline())
nodeparent = [0] * (nodenum + 1)
nodeparent[1] = 1
adj_list = [[] for i in range(nodenum + 1)]
for i in range(nodenum - 1):
    n1, n2 = map(int, sys.stdin.readline().split())
    adj_list[n1].append(n2)
    adj_list[n2].append(n1)
findParentNode(1)
for i in range(2, nodenum + 1):
    print(nodeparent[i])