#*
import sys
cardnumtobuy = int(sys.stdin.readline())
cardvalue_list = list(map(int, sys.stdin.readline().split()))
dp_list = [0 for i in range(len(cardvalue_list) + 1)]
dp_list[1] = cardvalue_list[0]
cardvalue_list.insert(0,0)
for i in range(2, cardnumtobuy + 1):
    for j in range(1, i + 1):
        dp_list[i] = max(dp_list[i], cardvalue_list[j] + dp_list[i - j])
print(dp_list[cardnumtobuy])
    