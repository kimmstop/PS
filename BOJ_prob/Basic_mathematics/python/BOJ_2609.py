import sys
import math
num1, num2 = map(int,sys.stdin.readline().split())
print(math.gcd(num1, num2))
print(math.lcm(num1, num2))