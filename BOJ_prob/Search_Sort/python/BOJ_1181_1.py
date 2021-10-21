import sys

numofword = int(sys.stdin.readline())
wordarr = set()
for i in range(numofword):
    word = sys.stdin.readline().rstrip()
    wordlen = len(word)
    wordarr.add(word)
wordarr = list(wordarr)
wordarr.sort()
wordarr.sort(key=lambda x:len(x))
print(wordarr)
print("\n".join(wordarr))