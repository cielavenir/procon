#!/usr/bin/python
from collections import defaultdict
import sys
n,m=map(int,sys.stdin.readline().split())
h=defaultdict(list)
vis=set()
for _ in range(m):
	a,b=map(int,sys.stdin.readline().split())
	h[a-1].append(b-1)
	h[b-1].append(a-1)
for i in range(n):
	if i in vis:continue
	vis.add(i)
	v=set([i])
	e=set()
	q=[i]
	while q:
		c=q.pop()
		for x in h[c]:
			z=tuple(sorted([c,x]))
			e.add(z)
			if x not in vis:
				vis.add(x)
				v.add(x)
				q.append(x)
	if len(e)!=len(v)*(len(v)-1)/2: break
else:
	print('YES')
	exit(0)
print('NO')
