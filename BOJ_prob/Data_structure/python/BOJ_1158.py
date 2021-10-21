import sys

if  __name__ == '__main__':
    numofpeople, delnum = map(int, sys.stdin.readline().split())
    circle = list(range(1, numofpeople + 1))
    deletedpeople = []
    idx = delnum
    for i in range(numofpeople):
        if len(circle) >= idx:
            deleted = circle.pop(idx -1)
            idx += delnum -1 
            deletedpeople.append(deleted)
        else:
            while idx > len(circle):
                idx -= len(circle)
            deleted = circle.pop(idx -1)
            idx += delnum - 1
            deletedpeople.append(deleted)

    deletedpeople = list(map(str, deletedpeople))
    print('<', end='')
    print(', '.join(deletedpeople), end='')
    print('>')