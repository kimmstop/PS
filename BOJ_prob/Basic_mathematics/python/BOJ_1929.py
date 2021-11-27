import sys
import math

def getRootNum(num):
    return int(math.sqrt(num))
def isPrime(num):
    if num == 1:
        return False
    rootnum = getRootNum(num)
    for i in range(2, rootnum + 1):
        if num % i == 0:
            return False
    return True
    
    
start, end = map(int,sys.stdin.readline().split())
for i in range(start, end + 1):
    if isPrime(i):
        print(i)