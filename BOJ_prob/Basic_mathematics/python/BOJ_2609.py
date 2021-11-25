import sys
num1, num2 = map(int,sys.stdin.readline().split())
gcd, lcm = 0, 0
for i in range(1, min(num1, num2) + 1):
    if num1 % i == 0 and num2 % i == 0:
        gcd = i
for i in range(max(num1, num2), num1 * num2 + 1, max(num1, num2)):
    if i % num1 == 0 and i % num2 == 0:
        lcm = i
        break
print(gcd)
print(lcm)