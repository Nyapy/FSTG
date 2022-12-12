import sys
ports = [0 for _ in range(10000+1)]
num = [0 for _ in range(10000+1)]

def binary(right, find):
    le,ri = 1, right
    while (le <ri):
        mid = (le+ri)//2
        if num[mid] <= find:
            le = mid+1
        else:
            ri = mid
    return le
T= int(input())
for tc in range(1,T+1):
    N,K = map(int, sys.stdin.readline().split())

    ports= [0]+list(map(int, sys.stdin.readline().split()))
    ans =0
    for i in range(1, N+1):
        maxlen = 0
        for j in range(i, N+1):
            if num[maxlen] < ports[j]:
                num[maxlen+1] = ports[j]
                maxlen+=1
            else:
                tem = binary(maxlen, ports[j])
                num[tem] = ports[j]
            if K==maxlen:
                ans=1
                break
    print("Case #{}".format(tc))
    print(ans)