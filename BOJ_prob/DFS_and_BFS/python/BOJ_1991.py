# A: 65 Z: 90 . : 46
import sys

def preorder(c_node):
    print(chr(c_node + 65), end = '')
    for i in range(2):
        if adj_list[c_node][i] != 46:
            preorder(adj_list[c_node][i] - 65)

def inorder(c_node):
    for i in range(2):
        if adj_list[c_node][i] != 46:
            inorder(adj_list[c_node][i] - 65)
        if i == 0:
            print(chr(c_node + 65), end = '')

def postorder(c_node):
    for i in range(2):
        if adj_list[c_node][i] != 46:
            postorder(adj_list[c_node][i] - 65)
    print(chr(c_node + 65), end = '')


nodenum = int(sys.stdin.readline())
adj_list = [[] for i in range(nodenum)]
for i in range(nodenum):
    treeinfo = list(map(ord, sys.stdin.readline().split()))
    for i in range(1, 3):
        adj_list[int(treeinfo[0]) - 65].append(treeinfo[i])

preorder(0)
print()
inorder(0)
print()
postorder(0)
    