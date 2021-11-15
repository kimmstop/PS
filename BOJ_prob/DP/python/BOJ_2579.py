import sys
numofstairs = int(sys.stdin.readline())
stairs = [0 for i in range(numofstairs)]
dp_list = [0 for i in range(numofstairs)]
for i in range(numofstairs):
    stairs[i] = int(sys.stdin.readline())

stairs.insert(0,0)
stairs.insert(0,0)
dp_list.insert(0,0)
dp_list.insert(0,0)
dp_list[2] = stairs[2]
for i in range(3, numofstairs + 2):
    t1 = dp_list[i -2] + stairs[i]
    t2 = dp_list[i -3] + stairs[i -1] +stairs[i]
    dp_list[i] = max(t1, t2)
print(dp_list[numofstairs + 1])