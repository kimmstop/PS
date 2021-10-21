import sys

from bisect import bisect_right

numofcard_have = int(input())
have_card = list(map(int, sys.stdin.readline().split()))
numofcard_cand = int(input())
candidate_card = list(map(int, sys.stdin.readline().split()))
have_card.sort()

for i in range(numofcard_cand):
    flag = bisect_right(have_card, candidate_card[i])
    if have_card[flag - 1] == candidate_card[i]:
        print(1, end = ' ')
    else:
        print(0, end = ' ')