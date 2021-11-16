#*
import sys
num = list(sys.stdin.readline().rstrip())
dp_list = [0 for i in range(len(num) + 1)]
dp_list[1] = 1
dp_list[0] = 1
num.insert(0,0)
if num[1] == '0':
    print(0)
else:
    for i in range(2, len(num)):
        if int(num[i]) > 0:
            dp_list[i] = dp_list[i - 1]
        cur_num = int(num[i -1]) * 10 + int(num[i])
        if cur_num <=26 and cur_num >= 10:
            dp_list[i] += dp_list[i -2]
    print(dp_list[len(num) - 1] % 1000000)