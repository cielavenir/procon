#!/usr/bin/python
import sys,heapq;(N,K),A=[map(int,s.split())for s in sys.stdin];z=0;q=[];
for a in A:
	N-=1;heapq.heappush(q,[a,N]);
	while q[0][1]>=N+K:heapq.heappop(q)
	z+=q[0][0]
print(z)
