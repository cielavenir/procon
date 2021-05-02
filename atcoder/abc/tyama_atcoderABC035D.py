#!/usr/bin/python
import sys
if sys.version_info[0]>=3:raw_input=input

from scipy.sparse import*
f=lambda*z:map(int,raw_input().split())
n,m,t=f();z=list(f());a,b,c=zip(*map(f,[0]*m))
g,h=[csgraph.dijkstra(csr_matrix((c,k),[n+1]*2),1,1)for k in[(a,b),(b,a)]]
print(int(max(z[i]*(t-g[i+1]-h[i+1])for i in range(n))))
