import sys

numofmeetings = int(sys.stdin.readline())
meetings = []
for i in range(numofmeetings):
    meetings.append(list(map(int, sys.stdin.readline().split())))
meetings.sort(key=lambda x:x[0])
meetings.sort(key=lambda x:x[1])
curendtime = meetings[0][1]
ans = 1
for i in range(1, len(meetings)):
    if meetings[i][0] >= curendtime:
        curendtime = meetings[i][1]
        ans += 1
print(ans)
        
    