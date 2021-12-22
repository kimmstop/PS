#*
import sys


def draw(cur_r, cur_c, part_size):
    if part_size == 3:
        picture[cur_r][cur_c] = '*'
        picture[cur_r + 1][cur_c -1] = picture[cur_r + 1][cur_c + 1] = '*'
        picture[cur_r + 2][cur_c - 2:cur_c + 3] = ['*'] * 5
    else:
        new_part_size = part_size // 2
        draw(cur_r, cur_c, new_part_size)
        draw(cur_r + new_part_size, cur_c - new_part_size, new_part_size)
        draw(cur_r + new_part_size, cur_c + new_part_size, new_part_size)


N = int(sys.stdin.readline())
picture = [[' ' for j in range(N * 2 - 1)] for i in range(N)]
draw(0, N - 1, N)
for i in picture:
    print(''.join(i))