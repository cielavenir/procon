#!/usr/bin/python
import sys
#if sys.version_info[0]>=3:raw_input=input

from scipy.sparse import*
g=[]
n=int(raw_input())
for _ in xrange(n-1):
	a,b=map(int,raw_input().split())
	g+=[(a-1,b-1,1)]
z=[-1]*n
for _ in xrange(int(raw_input())):
	a,b=map(int,raw_input().split())
	g+=[(n,a-1,b)]
	z[a-1]=b
a,b,c=zip(*g)
a=map(int,csgraph.dijkstra(csr_matrix((c,(a,b)),[n+1]*2),0,n))
for i in xrange(n):
	if z[i]>=0 and z[i]!=a[i]:
		print('No')
		sys.exit()
for e in g:
	if e[0]<e[1] and abs(a[e[0]]-a[e[1]])!=1:
		print('No')
		sys.exit()
print('Yes')
print("\n".join(map(str,a[:n])))
