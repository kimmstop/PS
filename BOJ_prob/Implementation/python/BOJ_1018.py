import sys

def test(start_r, start_c, case_flag):
    start_color = 'W'
    changed_block = 0
    for i in range(start_r, start_r + 8):
        if i % 2 == 0:
            if case_flag == 1:
                start_color = 'B'
            else:
                start_color = 'W'
        else:
            if case_flag == 1:
                start_color = 'W'
            else:
                start_color = 'B'
        for j in range(start_c, start_c + 8):
            if start_color == 'W' and j % 2 == 0 and board[i][j] != 'W':
                changed_block += 1
            elif start_color == 'W' and j % 2 != 0 and board[i][j] != 'B':
                changed_block += 1
            elif start_color == 'B' and j % 2 == 0 and board[i][j] != 'B':
                changed_block += 1
            elif start_color == 'B' and j % 2 != 0 and board[i][j] != 'W':
                changed_block += 1
    return changed_block


            




N, M = map(int, sys.stdin.readline().split())

board = []
min_change_block = 987654321
for i in range(N):
    board.append(sys.stdin.readline().rstrip())

for i in range(N - 7):
    for j in range(M - 7):
        min_change_block = min(min_change_block, min(test(i, j, 0), test(i, j, 1)))
print(min_change_block)