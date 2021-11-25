import sys
import math
testcasenum = int(sys.stdin.readline())
while testcasenum != 0:
    testcasenum -= 1
    num1, num2 = map(int, sys.stdin.readline().split())
    print(math.lcm(num1, num2))