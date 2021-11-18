#*
import sys
while True:
    s = sys.stdin.readline().rstrip('\n')
    l, b, n, w = 0, 0, 0, 0
    if not s:
        break
    for i in range(len(s)):
        if s[i].islower():
            l +=1
        if s[i].isupper():
            b +=1
        if s[i].isdigit():
            n +=1
        if s[i].isspace():
            w +=1
    print(l, b, n, w)
            
    