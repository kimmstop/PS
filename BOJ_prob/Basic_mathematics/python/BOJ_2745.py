import sys
num, base = sys.stdin.readline().split()
map_list= ['0']
char = 'A'
char1 = '1'
for i in range(1, 36):
    if i >= 10:
        map_list.append(char)
        char = chr(ord(char) + 1)
    else:
        map_list.append(char1)
        char1 = chr(ord(char1) + 1)
result = 0
digit = 1
for i in range(len(num) - 1, -1, -1):
    result = result +  digit * int(map_list.index(num[i]))
    digit *= int(base)
print(result)