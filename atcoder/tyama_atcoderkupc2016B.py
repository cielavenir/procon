#!/usr/bin/python
from collections import defaultdict
from heapq import *
import sys
d=defaultdict(int)
n,k=map(int,sys.stdin.readline().split())
for _ in range(n):
	s=sys.stdin.readline().strip()
	d[s[0]]-=1
if len(d)<k:
	print(0)
else:
	q=[]
	for khi in d:
		heappush(q,[d[khi],khi])
	r=0
	while 1:
		a=[heappop(q) for _ in range(k)]
		if any(e[0]==0 for e in a): break
		for e in a:
			e[0]+=1
			heappush(q,e)
		r+=1
	print(r)
