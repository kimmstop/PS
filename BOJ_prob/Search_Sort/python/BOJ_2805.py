import sys

tree_num, needed_tree_len = map(int, (sys.stdin.readline().split()))
tree_info = list(map(int, sys.stdin.readline().split()))
max_tree_height = max(tree_info)
min_tree_height = 0
while min_tree_height <= max_tree_height:
    machine_height = int((max_tree_height + min_tree_height) / 2)
    avail_tree_len = 0
    for i in tree_info:
        if i > machine_height:
            avail_tree_len = avail_tree_len + (i - machine_height)
    if avail_tree_len < needed_tree_len:
        max_tree_height = machine_height - 1
    elif avail_tree_len >= needed_tree_len:
        min_tree_height = machine_height + 1
print(max_tree_height)

