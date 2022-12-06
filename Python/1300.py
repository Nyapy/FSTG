
a = int(input())
b= int(input())

cnt = 0
flag = 0

left, right = 1, b+1
while(left < right):
    mid = (left+right)//2
    tem=0
    for i in range(1,a+1):
        tem += min(a, mid//i)

    if tem >= b:
        ans = mid
        right = mid
    else:
        left = mid+1

print(ans)