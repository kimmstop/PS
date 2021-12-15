#*
import sys

disc_num = int(sys.stdin.readline())

def moveDisc(cur_disc_num, first, second, third):
    if cur_disc_num == 1:
        print(first, third)
    else:
        moveDisc(cur_disc_num - 1, first, third, second)
        print(first, third)
        moveDisc(cur_disc_num - 1, second, first, third)
move_count = 1
for i in range(disc_num - 1):
    move_count = move_count * 2 + 1
print(move_count)
moveDisc(disc_num, 1, 2, 3)