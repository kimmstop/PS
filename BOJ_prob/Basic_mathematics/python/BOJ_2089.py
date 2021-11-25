#*
import sys
num = int(input())
conv_list = []
div = -2
if num == 0:
    print(0)
else:
    while num != 0:
        remain = num % div
        quot = num // div
        if remain < 0:
            remain += 2
            quot += 1
        conv_list.append(remain)
        num = quot
for i in conv_list[::-1]:
    print(i, end ='')