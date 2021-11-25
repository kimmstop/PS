import sys
num, base = map(int, (sys.stdin.readline().split()))
conv_list = []
map_list = [0]
char = 'A'
for i in range(1, 36):
    if i >= 10:
        map_list.append(char)
        char = chr(ord(char) + 1)
    else:
        map_list.append(i)
while num != 0:
    conv_list.append(num % base)
    num = int(num / base)
for i in range(len(conv_list) - 1 , -1,  -1):
    print(map_list[conv_list[i]], end = '')