#*
import sys

want_channel = int(sys.stdin.readline())
broken_button_num = int(sys.stdin.readline())
broken_button = []
ans = abs(want_channel - 100)
if broken_button_num != 0:
    broken_button = set(sys.stdin.readline().split())
else:
    broken_button = set()
for i in range(1000001):
    for j in range(len(str(i))):
        if str(i)[j] in broken_button:
            break
        elif j == len(str(i)) - 1:
            ans = min(ans, abs(i - want_channel) + len(str(i)))
print(ans)