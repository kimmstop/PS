import sys

if __name__ == '__main__':
    num = int(sys.stdin.readline())
    numlist = [987654321] * 1000001
    numlist[1] = 0
    numlist[2] = 1
    numlist[3] = 1
    for i in range(4, num + 1):
        if i > num:
            break
        if i % 3 == 0:
            numlist[i] = numlist[int(i / 3)] + 1
        if i % 2 == 0:
            if numlist[i] > numlist[int(i / 2)] + 1:
                numlist[i] = numlist[int(i / 2)] + 1
        if numlist[i] > numlist[i - 1] + 1:
            numlist[i] = numlist[i - 1] + 1
    
    print(numlist[num])