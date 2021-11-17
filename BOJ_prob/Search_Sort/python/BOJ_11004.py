import sys
N, K = map(int, sys.stdin.readline().split())
num_list = list(map(int, sys.stdin.readline().split()))
num_list.sort()
print(num_list[K - 1])