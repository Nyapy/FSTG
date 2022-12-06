import heapq
import sys

small = []
big = []

N = int(input())
for i in range(N):
    tem = int(sys.stdin.readline())
    if len(small) == len(big):
        heapq.heappush(small, -tem)
    else:
        heapq.heappush(big, tem)
    if small and big:
        if -small[0] > big[0]:
            tem = heapq.heappop(small)
            heapq.heappush(small, -heapq.heappop(big))
            heapq.heappush(big, -tem)
    print(-small[0])