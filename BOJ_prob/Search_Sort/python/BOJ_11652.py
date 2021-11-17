import sys
card_num = int(sys.stdin.readline())
card_dict = {}
for i in range(card_num):
    num = int(sys.stdin.readline())
    if num in card_dict:
        card_dict[num] += 1
    else:
        card_dict[num] = 1

result_list = sorted(card_dict.items(), key = lambda x: (-x[1], x[0]))
print(result_list[0][0])
        