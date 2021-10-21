import sys

if __name__ == '__main__':
    numofinst = int(sys.stdin.readline())
    listlikedeque = []
    for i in range(numofinst):
        inst = sys.stdin.readline().split()
        if inst[0] == 'push_front':
            op = int(inst[1])
            listlikedeque.insert(0, op)
        elif inst[0] == 'push_back':
            op = int(inst[1])
            listlikedeque.append(op)
        elif inst[0] == 'pop_front':
            if len(listlikedeque) == 0:
                print(-1)
            else:
                poppedval = listlikedeque.pop(0)
                print(poppedval)
        elif inst[0] == 'pop_back':
            if len(listlikedeque) == 0:
                print(-1)
            else:
                poppedval = listlikedeque.pop()
                print(poppedval)
        elif inst[0] == 'size':
            print(len(listlikedeque))
        elif inst[0] == 'empty':
            if len(listlikedeque) == 0:
                print(1)
            else:
                print(0)
        elif inst[0] == 'front':
            if len(listlikedeque) == 0:
                print(-1)
            else:
                print(listlikedeque[0])
        else:
            if len(listlikedeque) == 0:
                print(-1)
            else:
                print(listlikedeque[len(listlikedeque) - 1])


           