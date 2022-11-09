import heapq
import sys
import time
start = time.time()  # 시작 시간 저장

sys.stdin = open("01-01.txt")

M,N,K = map(int, input().split())
cnt = 0
xsw = [[] for _ in range(M+1)]
ysw = [[] for _ in range(N+1)]
xvisited = [[] for _ in range(M+1)]
yvisited = [[] for _ in range(N+1)]
for i in range(K):
    x,y = map(int, sys.stdin.readline().split())
    xsw[x].append(y)
    ysw[y].append(x)
    xvisited[x].append(9999999999)
    yvisited[y].append(9999999999)

pq = []
heapq.heappush(pq, [0,1,1,1])

ans = 0

if not xsw[M] and not ysw[N]:
    pq = []

xsw[M].append(N)
ysw[N].append(M)
xvisited[M].append(9999999999)
yvisited[N].append(9999999999)
dist =0
while pq:
    di,xy, x, y = heapq.heappop(pq)
    if x==M and y ==N:
        ans = di
        break
    if xy:
        for s,i in enumerate(xsw[x]):
            dist = di + abs(y - i)+1
            if xvisited[x][s] > dist:
                xvisited[x][s] = dist
                heapq.heappush(pq,[dist, 0, x, i])
    else:
        for s,i in enumerate(ysw[y]):
            dist = di + abs(x - i) + 1
            if yvisited[y][s] > dist:
                yvisited[y][s] = dist
                heapq.heappush(pq,[dist, 1, i, y])

print(ans-1)
print("현우 time :", time.time() - start)