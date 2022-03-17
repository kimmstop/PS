import sys

tire, work, rest, max_tire = map(int, (input().split()))
cur_tire = 0
work_done = 0
for i in range(24):
    if cur_tire + tire <= max_tire:
        work_done += work
        cur_tire += tire
    else:
        cur_tire -= rest
        if cur_tire <  0:
            cur_tire = 0
print(work_done)
        