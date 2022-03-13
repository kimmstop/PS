import sys


def findReal(cur_selectedNum, total_selectedNum, sumHeight):
    if total_selectedNum == 7 and sumHeight == 100:
        for i in range(9):
            if selected_info[i] == 1:
                print(height_info[i])
        exit()
    else:
        for i in range(cur_selectedNum, 9):
            selected_info[i] = 1
            findReal(i + 1, total_selectedNum + 1, sumHeight + height_info[i])
            selected_info[i] = 0




height_info = []
selected_info = [0] * 9
for i in range(9):
    height_info.append(int(sys.stdin.readline()))
height_info.sort()
findReal(0, 0, 0)
