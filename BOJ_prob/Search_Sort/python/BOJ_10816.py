import sys
from bisect import bisect_left

numofcard_have = int(sys.stdin.readline())
card_have = list(map(int, sys.stdin.readline().split()))
numofcard_cand = int(sys.stdin.readline())
card_cand = list(map(int, sys.stdin.readline().split()))
ans = [ 0 for i in range(20000001)]

for i in range(numofcard_have):
    if card_have[i] < 0:
        idx = card_have[i] + 20000001
        ans[idx] += 1
    else:
        ans[card_have[i]] += 1

for i in range(numofcard_cand):
    idx = card_cand[i]
    if card_cand[i] < 0:
        idx = card_cand[i] + 20000001
    if ans[idx] != 0:
        print(ans[idx], end=' ')
    else:
        print(0, end=' ')