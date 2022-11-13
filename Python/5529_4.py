import sys
import heapq
import time
start = time.time()  # 시작 시간 저장

sys.stdin = open("2013-ho-t3/in/01-05.txt")

M,N,K = map(int , input().split())

sw = [list(map(int, sys.stdin.readline().split()))+[i] for i in range(K)]
sw.append([M,N,K])
visited = [[999999999,999999999] for _ in range(K+1)]

adj = [[] for _ in range(K+1)]

sw.sort(key= lambda x:x[1])
for i in range(1,K+1):
    if sw[i][1] == sw[i-1][1]:
        adj[sw[i][2]].append(sw[i-1][2])
        adj[sw[i-1][2]].append(sw[i][2])

sw.sort(key= lambda x:x[0])
for i in range(1,K+1):
    if sw[i][0] == sw[i-1][0]:
        adj[sw[i][2]].append(sw[i-1][2])
        adj[sw[i-1][2]].append(sw[i][2])

pq=[]
if sw[0][0] == 1:
    heapq.heappush(pq, [sw[0][1]-1, sw[0][0],sw[0][1],sw[0][2], 1])
    visited[sw[0][2]][1] = sw[0][1]-1
    visited[sw[0][2]][0] = sw[0][1]
ans = 0

sw.sort(key= lambda x:x[2])
while pq:
    dist,x,y,k,c = pq.pop()
    if visited[k][c] != 999999999:
        continue
    if x==M and y == N:
        ans = dist
        break
    for i in adj[k]:
        nx,ny,nk = sw[i]
        if x == nx:
            nd = abs(ny-y)+dist
            if not c : nd +=1
            if visited[nk][1] > nd:
                visited[nk][1] = nd
                heapq.heappush(pq,[nd, nx,ny,nk, 1])
        elif y == ny:
            nd = abs(nx-x)+dist
            if c: nd +=1
            if visited[nk][0] > nd:
                visited[nk][0] = nd
                heapq.heappush(pq,[nd, nx,ny,nk, 0])


if ans:
    print(ans)
else:
    print(-1)

print("현우 time :", time.time() - start)