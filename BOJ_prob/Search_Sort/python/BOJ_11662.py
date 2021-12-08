#*
import sys
import math

def cal_dist(minho, gangho):
    a, b = minho
    c, d = gangho
    dist = math.sqrt(pow(a - c, 2)+ pow(b - d, 2))
    return dist

def get_minho_loc(p):
    return [x1 + (x2 - x1) * (p/100), y1 + (y2 - y1) * (p/100)]

def get_gangho_loc(p):
    return [x3 + (x4 - x3) * (p/100), y3 + (y4 - y3) * (p/100)]


x1, y1, x2, y2, x3, y3, x4, y4 = list(map(int, sys.stdin.readline().split()))
hi = 100
lo = 0
min_dist = 987654321
while hi - lo >= 1e-7:
    p1 = (lo * 2 + hi) / 3
    p2 = (lo + hi * 2) / 3
    minho_p1 = get_minho_loc(p1)
    minho_p2 = get_minho_loc(p2)
    gangho_p1 = get_gangho_loc(p1)
    gangho_p2 = get_gangho_loc(p2)
    dist_p1 = cal_dist(minho_p1, gangho_p1)
    dist_p2 = cal_dist(minho_p2, gangho_p2)
    
    if dist_p1 > dist_p2:
        lo = p1
    else:
        hi = p2
    min_dist = min(min_dist, min(dist_p1, dist_p2))
print(format(min_dist, ".10f"))