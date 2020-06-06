#!/usr/bin/env python3
import heapq
n,m=[int(e) for e in input().split()]
a=[int(e) for e in input().split()]
q=[[0,i] for i in range(1,n+1)]
heapq.heapify(q)
print(q)
for e in a:
	if q[0][0]<e:
		x=heapq.heappop(q)
		print(x[1])
		heapq.heappush(q,[e,x[1]])
	else:
		print(-1)
