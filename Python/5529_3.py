import heapq
import sys
import time
start = time.time()  # 시작 시간 저장

sys.stdin = open("01-01.txt")

M,N,K = map(int, input().split())
cnt = 0
xsw = [[] for _ in range(M+1)]
ysw = [[] for _ in range(N+1)]
visited = [[[],[]] for _ in range(100000+1)]
for i in range(K):
    x,y = map(int, sys.stdin.readline().split())
    xsw[x].append(y)
    ysw[y].append(x)
    visited[x][0].append(9999999999)
    visited[y][1].append(9999999999)

pq = []
heapq.heappush(pq, [0,1,1,1])

ans = 0

if not xsw[M] and not ysw[N]:
    pq = []

xsw[M].append(N)
ysw[N].append(M)
visited[M][0].append(9999999999)
visited[N][1].append(9999999999)
dist =0
while pq:
    di,xy, x, y = heapq.heappop(pq)
    if x==M and y ==N:
        ans = di
        break
    if xy:
        for s,i in enumerate(xsw[x]):
            dist = di + abs(y - i)+1
            if visited[x][0][s] > dist:
                visited[x][0][s] = dist
                heapq.heappush(pq,[dist, 0, x, i])
    else:
        for s,i in enumerate(ysw[y]):
            dist = di + abs(x - i) + 1
            if visited[y][1][s] > dist:
                visited[y][1][s] = dist
                heapq.heappush(pq,[dist, 1, i, y])

print(ans-1)
print("현우 time :", time.time() - start)