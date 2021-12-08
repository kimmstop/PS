#*
import sys

house_num, wifi_num = map(int, (sys.stdin.readline().split()))
house_info = []
for i in range(house_num):
    house_info.append(int(sys.stdin.readline()))
house_info.sort()

start_wifi = 1
last_wifi = house_info[len(house_info) - 1] - house_info[0]
dist = int((start_wifi + last_wifi) / 2)

while start_wifi <= last_wifi:
    
    installed_wifi = 1
    cur_loc = house_info[0]
    for i in range(1, len(house_info)):
        if house_info[i] >= cur_loc + dist:
            installed_wifi +=1
            cur_loc = house_info[i]
    if installed_wifi < wifi_num:
        last_wifi = dist - 1
    else:
        start_wifi = dist + 1
    dist = int((start_wifi + last_wifi) / 2)
print(dist)
  
