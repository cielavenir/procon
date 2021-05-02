#!/usr/bin/python
from scipy.sparse import*
f=lambda*z:map(int,raw_input().split());n,=f();a,b=zip(*map(f,[0]*~-n))
g,h=csgraph.dijkstra(csr_matrix(([1]*~-n,(a,b)),[n+1]*2),0,[1,n])
print['Snuke','Fennec'][sum(g[i]>h[i]for i in range(n+1))*2<n]
