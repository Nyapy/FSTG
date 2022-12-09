N = int(input())
ports = [0]+list(map(int, input().split()))

num = [0 for _ in range(N+1)]
maxlen= 1
num[1] = ports[1]

def binary(right, find):
    le,ri = 1, right
    while (le <ri):
        mid = (le+ri)//2
        if num[mid] <= find:
            le = mid+1
        else:
            ri = mid
    return le

# for i in range(2, N+1):
#     tem = binary(maxlen, ports[i])
#     if num[tem] > ports[i]:
#         num[tem] = ports[i]
#     else:
#         if not num[tem+1] or num[tem+1] > ports[i]:
#             num[tem+1] = ports[i]
#         if tem == maxlen:
#             maxlen+=1

for i in range(1, N+1):
    if num[maxlen] < ports[i]:
        num[maxlen+1] = ports[i]
        maxlen+=1
    else:
        tem = binary(maxlen, ports[i])
        num[tem] = ports[i]

print(maxlen)