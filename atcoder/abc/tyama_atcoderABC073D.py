#!/usr/bin/python
from scipy.sparse import*
f=lambda*z:map(int,raw_input().split())
N,M,R=f();r=f();a,b,c=list(zip(*map(f,[0]*M)))
a=csgraph.dijkstra(csr_matrix((c,(a,b)),[N+1]*2),0,r)
print int(min(sum(a[e[i]][r[e[i+1]]]for i in range(R-1))for e in __import__('itertools').permutations(range(R))))
