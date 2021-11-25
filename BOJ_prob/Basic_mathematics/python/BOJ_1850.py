#*
import sys
import math
num1_len, num2_len = map(int, sys.stdin.readline().split())
pre_gcd = math.gcd(num1_len, num2_len)
print('1' * pre_gcd)
