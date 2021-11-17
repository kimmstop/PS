import sys
member_num = int(sys.stdin.readline())
mem_info_list = []
for i in range(member_num):
    mem_info = sys.stdin.readline().split()
    mem_info_list.append(mem_info)
    mem_info[0] = int(mem_info[0])
mem_info_list.sort(key = lambda x:x[0])
for i in range(len(mem_info_list)):
    print(mem_info_list[i][0], mem_info_list[i][1])