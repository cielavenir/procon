#!/usr/bin/python
import sys,heapq
R=lambda:map(int,sys.stdin.readline().split())
x=list(R())
k=x.pop()
a=[sorted(R())for _ in range(3)]
h=set()
q=[[-sum(e[-1] for e in a)]+[e-1 for e in x]]
for _ in range(k):
	y=heapq.heappop(q)
	x=y.pop(0)
	print(-x)
	for i in range(3):
		ny=list(y)
		ny[i]-=1
		if y[i] and tuple(ny) not in h:
			h.add(tuple(ny))
			heapq.heappush(q,[x+a[i][y[i]]-a[i][y[i]-1]]+ny)
