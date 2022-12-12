T= int(input())


ports = [0 for _ in range(500+1)]
num = [0 for _ in range(500+1)]



def binary(right, find):
    le,ri = 1, right
    while (le <ri):
        mid = (le+ri)//2
        if num[mid] <= find:
            le = mid+1
        else:
            ri = mid
    return le

for tc in range(1,T+1):
    N = int(input())

    for i in range(1, N + 1):
        ports[i] = int(input())
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
            ans += maxlen

    print(ans)