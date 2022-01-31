import sys

num = list(map(int, sys.stdin.readline().rstrip()))
num.sort()
num.reverse()
sum = 0
for i in num:
    sum += i
if num[len(num) -1] == 0 and sum % 3 == 0:
    for i in num:
        print(i, end = '')
else:
    print(-1)