import sys
future_base, cur_base = map(int, sys.stdin.readline().split())
future_num_count = int(sys.stdin.readline())
future_num = list(map(int, sys.stdin.readline().split()))
future_num_base10 = 0
cur_num = []
digit = 1
for i in future_num[::-1]:
    future_num_base10 += digit * i
    digit *= future_base
while future_num_base10 != 0:
    cur_num.append(future_num_base10 % cur_base)
    future_num_base10 = future_num_base10 // cur_base
for i in cur_num[::-1]:
    print(i, end= ' ')