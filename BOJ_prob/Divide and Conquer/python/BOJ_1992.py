import sys

def divide_video(cur_r, cur_c, part_size):
    standard = video[cur_r][cur_c]
    for i in range(part_size):
        for j in range(part_size):
            new_part_size = int(part_size / 2)
            if video[cur_r + i][cur_c + j] != standard:
                result.append('(')
                for k in range(4):
                    divide_video(cur_r + (k // 2) * new_part_size, cur_c + (k % 2) * new_part_size, new_part_size)
                result.append(')')
                return
    result.append(standard)


video_size = int(sys.stdin.readline())
video = [[] for i in range(video_size)]
result = []
for i in range(video_size):
    video[i] = list(sys.stdin.readline().rstrip())

divide_video(0, 0, video_size)
for i in result:
    print(i, end= '')