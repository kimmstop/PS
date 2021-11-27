import sys

num = int(sys.stdin.readline())
prime_list = []
result = []
div = 2
while num != 1:
    if num % div == 0:
        result.append(div)
        num = int(num / div)
    else:
        div +=1
for i in result:
    print(i)
    
        