import sys
numarr =[]
for i in range(int(sys.stdin.readline())):
    numarr.append(int(sys.stdin.readline()))

numarr.sort()
numarr = list(map(str, numarr))
print('\n'.join(numarr))

    