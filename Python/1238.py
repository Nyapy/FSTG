import heapq

N,M,X = map(int, input().split())

back = [[] for _ in range(N+1)]
go = [[] for _ in range(N+1)]

dist_go = [1000000 for _ in range(N+1)]
dist_back = [1000000 for _ in range(N+1)]

for _ in range(M):
    s,e,t = map(int, input().split())
    back[s].append([e,t])
    go[e].append([s,t])



pq = []
heapq.heappush(pq, [0,X])
while pq:
    time,city =heapq.heappop(pq)
    if dist_go[city] != 1000000:
        continue
    dist_go[city] = time

    for c,t in go[city]:
        if dist_go[c] > time+t:
            heapq.heappush(pq, [t+time,c])

heapq.heappush(pq, [0,X])
while pq:
    time,city = heapq.heappop(pq)
    if dist_back[city] != 1000000:
        continue
    dist_back[city] = time

    for c, t in back[city]:
        if dist_back[c] > time + t:
            heapq.heappush(pq, [t + time,c])
ans = 0
for i in range(1,N+1):
    if ans < dist_go[i]+dist_back[i]:
        ans = dist_go[i]+dist_back[i]
print(ans)