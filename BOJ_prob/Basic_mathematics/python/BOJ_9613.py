import sys
import math
testcasenum = int(sys.stdin.readline())
while testcasenum != 0:
    testcasenum -= 1
    num_list = list(map(int, sys.stdin.readline().split()))
    sum = 0
    for i in range(1, len(num_list)):
        for j in range(i + 1, len(num_list)):
            sum += math.gcd(num_list[i], num_list[j])
    print(sum)