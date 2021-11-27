import sys
import math
def getRootNum(num):
    rootnum = int(math.sqrt(num))
    return rootnum

def isPrime(num, rootnum):
    if num == 1:
        return False
    for i in range(2, rootnum + 1):
        if num % i == 0:
            return False
    return True
        
num_count = int(sys.stdin.readline())
prime_count = 0
num_list = list(map(int, sys.stdin.readline().split()))
for i in num_list:
    rootnum = getRootNum(i)
    if isPrime(i, rootnum):
        prime_count += 1
print(prime_count)
    