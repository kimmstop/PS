import sys

female, male, internship = map(int, sys.stdin.readline().split())
avail_team = 0
while female >= 2 and male >= 1 and female + male >= internship + 3:
    female -= 2
    male -= 1
    avail_team +=1
print(avail_team)
    
        
            