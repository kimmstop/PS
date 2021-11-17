import sys
student_num = int(sys.stdin.readline())
student_score_list =[]
for i in range(student_num):
    student_score = sys.stdin.readline().split()
    for i in range(1, 4):
        student_score[i] = int(student_score[i])
    student_score_list.append(student_score)
student_score_list.sort(key = lambda x: (-int(x[1]), int(x[2]), -int(x[3]), x[0]))
for i in range(student_num):
    print(student_score_list[i][0])
