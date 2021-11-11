import sys
total_num = int(sys.stdin.readline())
dp_list = [0 for i in range(total_num)]
select_list = [0 for i in range(total_num)]
amount = []
for i in range(total_num):
    amount.append(int(sys.stdin.readline()))

amount.insert(0,0)
amount.insert(0,0)
amount.insert(0,0)
dp_list.insert(0,0)
dp_list.insert(0,0)
dp_list.insert(0,0)
for i in range(3, total_num + 3):
    dp_list[i] = max(dp_list[i -1], dp_list[i -3] + amount[i -1] + amount[i], dp_list[i-2] + amount[i])
print(dp_list[total_num + 2])