import sys

n, m = map(int, sys.stdin.readline().split())

def count2(num):
    numof2 = 0
    while num != 0:
        num = num // 2
        numof2 += num
    return numof2

def count5(num):
    numof5 = 0
    while num != 0:
        num = num // 5
        numof5 += num
    return numof5

total2 = count2(n) - count2(n - m) - count2(m)
total5 = count5(n) - count5(n - m) - count5(m)
print(min(total2, total5))