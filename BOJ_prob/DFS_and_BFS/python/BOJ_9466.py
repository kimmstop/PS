#*
import sys
sys.setrecursionlimit(10 ** 6)

def MakeTeam(start_student, first_student):
    global isselected
    team.append(start_student)
    visit[start_student] = 1
    next_student = selectedstudentnum[start_student - 1]
    if visit[next_student] == 1:
        if next_student in team:
            isselected += team[team.index(next_student):]
        return
    else:
        MakeTeam(next_student, first_student)

testcasenum = int(sys.stdin.readline())
while testcasenum != 0:
    testcasenum -= 1
    totalstudentnum = int(sys.stdin.readline())
    selectedstudentnum = list(map(int, sys.stdin.readline().split()))
    isselected = []
    visit = [0] * (totalstudentnum + 1)
    for i in range(1, totalstudentnum + 1):
        if visit[i] == 0:
            team = []
            MakeTeam(i, i)

    print(totalstudentnum - len(isselected))
    