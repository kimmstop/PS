import sys

already_have_LAN_num, needed_LAN_num = map(int, sys.stdin.readline().split())
already_have_LAN_info = []
for i in range(already_have_LAN_num):
    already_have_LAN_info.append(int(sys.stdin.readline()))
max_LAN_len = 1

already_have_LAN_info.sort()
min_LAN_len = 0
max_LAN_len = already_have_LAN_info[len(already_have_LAN_info) - 1] + 1
LAN_len = int((0 + max_LAN_len) / 2)
while True:
    divided_LAN_num = 0
    if min_LAN_len == max_LAN_len - 1:
        break
    for i in already_have_LAN_info:
        divided_LAN_num = divided_LAN_num + (i // LAN_len)
    if divided_LAN_num >= needed_LAN_num:
        min_LAN_len = LAN_len
        LAN_len = int((LAN_len + max_LAN_len) / 2) 
    elif divided_LAN_num < needed_LAN_num:
        max_LAN_len = LAN_len
        LAN_len = int((LAN_len + min_LAN_len) / 2)
print(LAN_len)
    