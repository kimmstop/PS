#*
import sys

def draw(cur_r, cur_c, part_size):
    if part_size == 3:
        result[cur_r][cur_c:cur_c+3] = [1] * 3
        result[cur_r + 1][cur_c:cur_c+3] = [1, 0, 1]
        result[cur_r + 2][cur_c:cur_c+3] = [1] * 3
    else:
        for i in range(9):
            if i == 4:
                continue
            new_part_size = part_size // 3
            draw(cur_r + (i // 3) * new_part_size, cur_c + (i % 3) * new_part_size, new_part_size)
        
        
        
result_size = int(sys.stdin.readline())
result = [[0 for j in range(result_size)] for i in range(result_size)]

draw(0, 0, result_size)
for i in result:
    for j in i:
        if j == 1:
            print("*", end = '')
        else:
            print(" ", end = '')
    print()

