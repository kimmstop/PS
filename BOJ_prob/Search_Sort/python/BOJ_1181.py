import sys

numofword = int(sys.stdin.readline())
wordarrbylen = [[] for i in range(52)]
for i in range(numofword):
    word = sys.stdin.readline()
    wordlen = len(word)
    wordarrbylen[wordlen].append(word)

for i in range(52):
    wordarrbylen[i].sort()

for i in range(52):
    for j in range(len(wordarrbylen[i])):
        if wordarrbylen[i][j] == wordarrbylen[i][j-1] and j != 0:
            continue
        print(wordarrbylen[i][j], end='')
