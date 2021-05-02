#!/usr/bin/python
import sys
from scipy.sparse import*
g=[]
n=int(sys.stdin.readline())
for _ in xrange(n-1):
	a,b=map(int,sys.stdin.readline().split())
	g.append((a-1,b-1,1))
z=[-1]*n
for _ in xrange(int(sys.stdin.readline())):
	a,b=map(int,sys.stdin.readline().split())
	g.append((n,a-1,b))
	z[a-1]=b
a,b,c=zip(*g)
a=map(int,csgraph.dijkstra(csr_matrix((c,(a,b)),[n+1]*2),0,n))
for i in xrange(n):
	if z[i]>=0 and z[i]!=a[i]:
		print('No')
		exit()
for e in g:
	if e[0]<e[1] and abs(a[e[0]]-a[e[1]])!=1:
		print('No')
		exit()
print('Yes')
print("\n".join(map(str,a[:n])))
