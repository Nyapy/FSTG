from collections import deque
import heapq
N,K = map(int, input().split())

visited = [-1 for _ in range(200000+1)]
ans =0
q=[]
if N != K:
    q.append([0,N])
    visited[N] =0
    while q:
        if ans: break
        time, t = heapq.heappop(q)
        if 0<2*t <= 200000:
            if visited[2*t]== -1:
                visited[2*t] = visited[t]
                heapq.heappush(q,[visited[2*t], 2*t])
                if 2*t == K:
                    ans = visited[t]
                    break
        for i in [-1,+1]:
            nt = t+i
            if 0<= nt <= 200000:
                if visited[nt] == -1:
                    visited[nt] = visited[t]+1
                    heapq.heappush(q,[visited[nt], nt])
                    if nt == K:
                        ans = visited[nt]
                        break
    print(ans)
else:
    print(ans)



