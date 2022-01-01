import sys

female, male, internship = map(int, sys.stdin.readline().split())
avail_team = 0
if female > male * 2:
    avail_team = male
    remain_female = female - male * 2
    if remain_female < internship:
        internship = internship - remain_female - 1
        avail_team = avail_team - (internship // 3 + 1)        
elif female ==  male * 2:
    avail_team = female // 2
    if internship > 0:
        internship -= 1
        avail_team = avail_team - (internship // 3 + 1)
else:
    avail_team = female // 2
    remain_male = male - female // 2
    if remain_male < internship:
        internship = internship - remain_male - 1
        avail_team = avail_team - (internship // 3 + 1)        
print(avail_team)
    
        
            