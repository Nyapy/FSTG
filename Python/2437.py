N= int(input())
chu = list(map(int, input().split()))
now=0
chu.sort()
for i in range(N):
    if chu[i] <= now+1:
        now += chu[i]
    else:
        break
print(now+1)