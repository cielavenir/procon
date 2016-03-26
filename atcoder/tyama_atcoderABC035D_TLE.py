#!/usr/bin/python
from scipy.sparse import *
import numpy,sys
if sys.version_info[0]>=3: raw_input=input
inf=float('inf')
n,m,t=map(int,raw_input().split())
z=list(map(int,raw_input().split()))
g=dok_matrix((n,n),dtype=numpy.int64)
h=dok_matrix((n,n),dtype=numpy.int64)
for _ in range(m):
	a,b,c=map(int,raw_input().split())
	a-=1
	b-=1
	g[a,b]=c
	h[b,a]=c
g=csgraph.dijkstra(g,indices=0)
h=csgraph.dijkstra(h,indices=0)
print(int(max(z[i]*(t-g[i]-h[i]) for i in range(n))))