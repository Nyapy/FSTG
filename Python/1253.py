N= int(input())
arr = list(map(int, input().split()))
ans=0
arr.sort()
if N <=2:
    print(0)
else:
    for i in range(N):
        f=0
        e=N-1
        while (f<e):
            if(f==i) :
                f+=1
                continue
            elif (e==i):
                e-=1
                continue
            if(arr[f]+arr[e] == arr[i]):
                ans+=1
                break
            if(arr[f]+arr[e] <arr[i]):
                f+=1
            else:
                e-=1
    print(ans)