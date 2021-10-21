import sys

if __name__ == '__main__':
    numofinst = int(sys.stdin.readline())
    listlikestack = []
    for i in range(numofinst):
        inst= sys.stdin.readline().split()
        if inst[0] == 'push':
            op = int(inst[1])
            listlikestack.append(op)
        elif inst[0] == 'pop':
            if len(listlikestack) == 0:
                print(-1)
            else:
                poppedval = listlikestack.pop()
                print(poppedval)
        elif inst[0] == 'size':
            print(len(listlikestack))
        elif inst[0] == 'empty':
            if len(listlikestack) == 0:
                print(1)
            else:
                print(0)
        else:
            if len(listlikestack) == 0:
                print(-1)
            else:
                print(listlikestack[len(listlikestack) - 1])
