import sys

N, K = map(int, sys.stdin.readline().split())
money = []
for i in range(N):
    money.append(int(sys.stdin.readline()))
cur_money = 0
coincount = 0
for i in range(len(money) - 1, -1, -1):
    if  money[i] <= K:
        coincount = coincount + K // money[i]
        K = K - money[i] * (K // money[i])
    if K == 0:
        break
print(coincount)
    