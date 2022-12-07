import heapq
N,M = map(int, input().split())
arr = [[0,[]] for _ in range(N+1)]
visited = [0 for _ in range(N+1)]
for _ in range(M):
    a,b = map(int, input().split())
    arr[b][0] = a
    arr[a][1].append(b)

q =[]
for i in range(1,N+1):
    if q:
        while q and q[0] <=i :
            tem = heapq.heappop(q)
            if visited[tem]: continue
            print(tem, end=" ")
            visited[tem] =1
            for j in arr[tem][1]:
                heapq.heappush(q, j)

    if not visited[i] :
        tem = i
        while arr[tem][0]:
            tem = arr[tem][0]
        heapq.heappush(q, tem)