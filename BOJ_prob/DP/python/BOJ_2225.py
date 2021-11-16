import sys
N, K = map(int, sys.stdin.readline().split())
dp_list = [[0 for i in range(201)] for j in range(201)]
for i in range(201):
    dp_list[i][1] = 1
    dp_list[1][i] = i
for i in range(2, 201):
    for j in range(2, 201):
        dp_list[i][j] = dp_list[i-1][j] + dp_list[i][j-1]
print(dp_list[N][K] % 1000000000)
       