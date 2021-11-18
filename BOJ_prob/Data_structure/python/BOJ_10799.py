import sys
laser_point =[]
stick_point = []
stack = []
exp = list(sys.stdin.readline().rstrip())
cur_stick_num = 0
divided_stick = 0
stack.append(0)
for i in range(1, len(exp)):
    if exp[i] == ')' and exp[i - 1] == '(':
        stack.pop()
        divided_stick += len(stack)
    elif exp[i] == ')' and exp[i -1] == ')':
        stack.pop()
        divided_stick += 1
    elif exp[i] == '(':
        stack.append(i)

print(divided_stick)