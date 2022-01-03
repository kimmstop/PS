#*
import sys
csize, rsize = map(int, sys.stdin.readline().split())
visit_point = 1
if csize == 1:
    print(1)
elif csize == 2:
    print(min(4, (rsize + 1) // 2))
else:
    if rsize >= 6:
        print(rsize - 2)
    else:
        print(min(4, rsize))
    
    
