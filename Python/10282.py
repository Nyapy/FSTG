import sys
import heapq
T = int(input())

for tc in range(1,T+1):
    n,d,c = map(int, sys.stdin.readline().split())
    depend = [[] for _ in range(n+1)]
    visited = [10000001 for _ in range(n+1)]
    for i in range(d):
        a,b,s = map(int, sys.stdin.readline().split())
        depend[b].append([a,s])
    pq = []
    heapq.heappush(pq,[0,c])
    ans = 0
    atime =0
    while pq:
        time,com = heapq.heappop(pq)
        if visited[com] < time:
            continue
        visited[com] = time
        for nc, nt in depend[com]:
            if visited[nc] > nt + time:
                heapq.heappush(pq,[nt+time,nc])
    for i in range(1,n+1):
        if visited[i] != 10000001:
            ans +=1
            if atime < visited[i]:
                atime = visited[i]
    print(ans, atime)