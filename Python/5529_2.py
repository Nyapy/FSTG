import heapq
import sys

import time
start = time.time()  # 시작 시간 저장

sys.stdin = open("01-01.txt")

M, N, K = map(int, sys.stdin.readline().split())

max_val = 9999999999
cnt = 0
X_LINE = [[] for _ in range(M)]
Y_LINE = [[] for _ in range(N)]
X_LINE_vis = [[] for _ in range(M)]
Y_LINE_vis = [[] for _ in range(N)]

for i in range(K):
    X, Y = map(int, sys.stdin.readline().split())
    X_LINE[X - 1].append(Y - 1)
    Y_LINE[Y - 1].append(X - 1)
    X_LINE_vis[X - 1].append(max_val)
    Y_LINE_vis[Y - 1].append(max_val)

# 0:가로이동 1: 세로이동
# 초기값 설정
heap = []

if X_LINE[0]:
    heapq.heappush(heap, (max_val * (-1), 0, 0, 1))
    X_LINE_vis[0][0] = max_val
ans = max_val

if not X_LINE[-1] and not Y_LINE[-1]:
    heap = []

if not X_LINE[-1] or X_LINE[-1][-1] != N - 1:
    X_LINE[M - 1].append(N - 1)
    Y_LINE[N - 1].append(M - 1)
    X_LINE_vis[-1].append(max_val)
    Y_LINE_vis[-1].append(max_val)

for i in range(M):
    X_LINE[i].sort()
for i in range(N):
    Y_LINE[i].sort()

while heap:

    scr, X, Y, DIR = heapq.heappop(heap)
    if scr >= ans:
        continue
    if X == M - 1 and Y == N - 1:
        ans = scr
        break;
    if DIR:
        for i, x in enumerate(X_LINE[X]):
            cnt += 1
            if scr + abs(Y - x) + 1 < X_LINE_vis[X][i]:
                X_LINE_vis[X][i] = scr + abs(Y - x) + 1
                heapq.heappush(heap, (X_LINE_vis[X][i], X, x, 0))
    else:
        for i, y in enumerate(Y_LINE[Y]):
            cnt += 1
            if scr + abs(X - y) + 1 < Y_LINE_vis[Y][i]:
                Y_LINE_vis[Y][i] = scr + abs(X - y) + 1
                heapq.heappush(heap, (Y_LINE_vis[Y][i], y, Y, 1))

if ans == max_val:
    print(-1)
else:
    print(ans + max_val - 1)

print(cnt)

print("찬환 time :", time.time() - start)