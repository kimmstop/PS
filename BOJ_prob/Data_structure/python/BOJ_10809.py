import sys
S = list(sys.stdin.readline().rstrip())
alph_list = [0 for i in range(26)]
c = 97

for i in range(len(alph_list)):
    try : 
        alph_list[c - 97] = S.index(chr(c))
    except ValueError as e:
        alph_list[c - 97] = -1
    c+=1
for i in range(len(alph_list)):
    print(alph_list[i], end = ' ')
    