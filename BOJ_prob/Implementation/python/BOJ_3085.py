import sys

def switchCandy(r, c, dir):
    tmp = candy[r][c]
    if dir == 0:
        candy[r][c] = candy[r][c + 1]
        candy[r][c + 1] = tmp
    else:
        candy[r][c] = candy[r + 1][c]
        candy[r + 1][c] = tmp


def countMaxCandyinRow(r):
    cur_m = 1
    m = 1
    for i in range(boardSize):
        if i + 1 < boardSize and candy[r][i] == candy[r][i + 1]:
            cur_m += 1
            m = max(m, cur_m)
        elif i + 1 < boardSize and candy[r][i] != candy[r][i + 1]:
            cur_m = 1
    return m

def countMaxCandyinCol(c):
    cur_m = 1
    m = 1
    for i in range(boardSize):
        if i + 1 < boardSize and candy[i][c] == candy[i + 1][c]:
            cur_m += 1
            m = max(m, cur_m)
        elif i + 1 < boardSize and candy[i][c] != candy[i + 1][c]:
            cur_m = 1
    return m


boardSize = int(input())
candy = []
for i in range(boardSize):
    candy.append(list(sys.stdin.readline().rstrip()))
maxCandyEat = 0

for i in range(boardSize):
    maxCandyEat = max(maxCandyEat, max(countMaxCandyinRow(i), countMaxCandyinCol(i)))




for i in range(boardSize):
    for j in range(boardSize):
        if j + 1 < boardSize and candy[i][j] != candy[i][j + 1]:
            switchCandy(i, j, 0)
            maxCandyEat = max(maxCandyEat, max(countMaxCandyinRow(i), max(countMaxCandyinCol(j), countMaxCandyinCol(j + 1))))
            switchCandy(i, j, 0)
        if i + 1 < boardSize and candy[i][j] != candy[i + 1][j]:
            switchCandy(i, j, 1)
            maxCandyEat = max(maxCandyEat, max(countMaxCandyinCol(j), max(countMaxCandyinRow(i), countMaxCandyinRow(i + 1))))
            switchCandy(i, j, 1)
print(maxCandyEat)