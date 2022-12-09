import heapq
N,M = map(int, input().split())

cnt = [0 for _ in range(N+1)]
arr = [[] for _ in range(N+1)]
visited = [0 for _ in range(N+1)]
for _ in range(M):
    a,b = map(int, input().split())
    cnt[b] +=1
    arr[a].append(b)

q =[]
for i in range(1,N+1):
    if not cnt[i]:
        heapq.heappush(q, i)

while q:
    tem = heapq.heappop(q)
    print(tem, end=" ")
    for i in arr[tem]:
        cnt[i] -=1
        if not cnt[i]:
            heapq.heappush(q, i)