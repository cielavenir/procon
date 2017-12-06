#!/usr/bin/python
import heapq
n,k=map(int,raw_input().split());r=0
a=[[int(f) for f in raw_input().split()] for _ in range(n)]
heapq.heapify(a)
for _ in range(k):
	c=heapq.heappop(a);r+=c[0];heapq.heappush(a,[c[0]+c[1],c[1]])
print r
