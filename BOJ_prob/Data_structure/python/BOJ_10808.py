import sys
S = list(sys.stdin.readline().rstrip())
alph_list = [0 for i in range(26)]
for i in range(len(S)):
    alph_list[ord(S[i]) - 97] += 1
for i in range(len(alph_list)):
    print(alph_list[i], end= ' ')
    
    