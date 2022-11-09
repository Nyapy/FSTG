import time
import heapq
start = time.time()  # 시작 시간 저장
print("time :", time.time() - start)
pq = []
i = 0
while i<10000000:
    heapq.heappush(pq, [i,1,2,3,4,5,6,7])
    i+=1;
    heapq.heappop(pq)
