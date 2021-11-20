import sys
s = list(sys.stdin.readline().rstrip())
for i in range(len(s)):
    if s[i].isupper():
        t = ord(s[i]) + 13
        if t > 90:
            t -= 26
        s[i] = chr(t)
    if s[i].islower():
        t = ord(s[i]) + 13
        if t > 122:
            t -= 26
        s[i] = chr(t)
for i in range(len(s)):
    print(s[i], end= '')