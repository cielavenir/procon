#!/usr/bin/python
import sys,heapq
_,a,q=[[-int(e) for e in sys.stdin.readline().split() if e!='0'] for _ in[0]*3]
heapq.heapify(q)
for e in a:
	t=[]
	for _ in [0]*-e:
		if not q:print(0);exit()
		if q[0]!=-1:heapq.heappush(t,q[0]+1)
		heapq.heappop(q)
	while t:heapq.heappush(q,t[0]);heapq.heappop(t)
print(int(not q))



