import sys

def countPaper(cur_r, cur_c, part_size):
    for i in range(part_size):
        for j in range(part_size):
            paper_class[paper[cur_r + i][cur_c + j] + 1] += 1

def isPaperUnified(cur_r, cur_c, part_size):
    standard = paper[cur_r][cur_c]
    for i in range(part_size):
        for j in range(part_size):
            if paper[cur_r + i][cur_c + j] != standard:
                new_part_size = int(part_size / 3)
                if new_part_size == 1:
                    countPaper(cur_r, cur_c, part_size)
                    return
                index = 0
                for k in range(9):
                    isPaperUnified(cur_r + int(k / 3) * new_part_size, cur_c + int(index % 3) * new_part_size, new_part_size)
                    index += 1
                return
    
    paper_class[standard + 1] += 1

paper_size = int(sys.stdin.readline())
paper = [[] for i in range(paper_size)]
paper_class = [0, 0, 0]
for i in range(paper_size):
    paper[i] = (list(map(int, sys.stdin.readline().split())))
isPaperUnified(0, 0, paper_size)
for i in paper_class:
    print(i)

