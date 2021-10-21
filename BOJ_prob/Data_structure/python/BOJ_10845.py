import sys

if __name__ == '__main__':
    numofinst = int(sys.stdin.readline())
    listlikequeue = []
    for i in range(numofinst):
        inst = sys.stdin.readline().split()
        if inst[0] == 'push':
           op = int(inst[1])
           listlikequeue.append(op)
        elif inst[0] == 'pop':
            if len(listlikequeue) == 0:
                print(-1)
            else:
                poppedval = listlikequeue.pop(0)
                print(poppedval)
        elif inst[0] == 'size':
            print(len(listlikequeue))
        elif inst[0] == 'empty':
            if len(listlikequeue) == 0:
                print(1)
            else:
                print(0)
        elif inst[0] == 'front':
            if len(listlikequeue) == 0:
                print(-1)
            else:
                print(listlikequeue[0])
        else:
            if len(listlikequeue) == 0:
                print(-1)
            else:
                print(listlikequeue[len(listlikequeue) - 1])


           