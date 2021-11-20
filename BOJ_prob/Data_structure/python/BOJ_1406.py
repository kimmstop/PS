#*
import sys
stack1 = list(sys.stdin.readline().rstrip())
stack2 = []
inst_num = int(input())
for i in range(inst_num):
    inst = list(sys.stdin.readline().split())
    if inst[0] == 'L':
        if len(stack1) != 0:
            stack2.append(stack1.pop())
    elif inst[0] == 'D':
        if len(stack2) != 0:
            stack1.append(stack2.pop())
    elif inst[0] == 'B':
        if  len(stack1) != 0:
            stack1.pop()
    else:
       stack1.append(inst[1])
print("".join(stack1 + list(reversed(stack2))))