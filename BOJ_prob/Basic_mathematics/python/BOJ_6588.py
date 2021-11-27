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

def isOdd(num):
    return num % 2

def getMaxPrime_Odd(num):
    for i in range(num - 1, 1, -1):
        if isPrime(i) and isOdd(i):
            return i
    
    
while True:
    num = int(sys.stdin.readline())
    if num == 0:
        break
    num_range = num
    while True:
        max_prime = getMaxPrime_Odd(num_range)
        cand = num - max_prime
        if cand > max_prime:
            print("Goldbach's conjecture is wrong.")
            break
        if isPrime(cand) and isOdd(cand):
            print("{0} = {1} + {2}".format(num, cand, max_prime))
            break
        num_range = max_prime
        
    