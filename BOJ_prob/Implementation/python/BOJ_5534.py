import sys


def canRecycle(oldSign):
    first_char_loc = []
    second_char_loc = []
    cvName_idx = 2
    for i in range(len(oldSign)):
        if cvName[0] == oldSign[i]:
            first_char_loc.append(i)
        elif cvName[1] == oldSign[i]:
            second_char_loc.append(i)
    for i in first_char_loc:
        for j in second_char_loc:
            flag = 0
            if i < j:
                loc_diff = j - i
                for k in range(cvName_idx, len(cvName)):
                    if j + loc_diff * (k - 1) < len(oldSign) and cvName[k] == oldSign[j + loc_diff * (k - 1)]:
                        continue
                    else:
                        flag = 1
                        break
                if flag == 0:
                    return True
    return False
        







oldSignNum = int(input())
cvName = sys.stdin.readline().rstrip()
availSignNum = 0

for i in range(oldSignNum):
    oldSign = sys.stdin.readline().rstrip()
    if(canRecycle(oldSign)):
        availSignNum += 1

print(availSignNum)



