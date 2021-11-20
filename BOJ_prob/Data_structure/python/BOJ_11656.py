import sys
S = input()
suffix_list = []
for i in range(len(S)):
    suffix_list.append(S[i:])
suffix_list.sort()
for i in range(len(suffix_list)):
    print(suffix_list[i])