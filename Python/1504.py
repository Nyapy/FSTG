import sys
import heapq

N,E = map(int, input().split())

adj = [[] for _ in range(N+1)]

dist1 = [987654321 for _ in range(N+1)]
dist2 = [987654321 for _ in range(N+1)]

for _ in range(E):
    a,b,c = map(int, sys.stdin.readline().split())
    adj[b].append([a,c])
    adj[a].append([b,c])

v1,v2 = map(int, input().split())

pq = []

heapq.heappush(pq,[0,v1])
visited = [0 for _ in range(N+1)]
dist1[v1] =0
while pq:
    dist, node = heapq.heappop(pq)
    if visited[node] ==1:
        continue
    visited[node] = 1
    for nn,nd in adj[node]:
        if dist1[nn] > nd+dist:
            dist1[nn] = nd+dist
            heapq.heappush(pq,[nd+dist, nn])

heapq.heappush(pq,[0,v2])
visited = [0 for _ in range(N+1)]
dist2[v2] =0
while pq:
    dist, node = heapq.heappop(pq)
    if visited[node] ==1:
        continue
    visited[node] = 1
    for nn,nd in adj[node]:
        if dist2[nn] > nd+dist:
            dist2[nn] = nd+dist
            heapq.heappush(pq,[nd+dist, nn])
nodap = 0

if visited[1] ==0 or visited[N] == 0 or visited[v1]==0:
    nodap = 1

ans = dist1[1]+dist1[v2]+dist2[N]
ans2 = dist2[1]+dist2[v1]+dist1[N]

if nodap:
    print(-1)
else:
    print(min(ans,ans2))