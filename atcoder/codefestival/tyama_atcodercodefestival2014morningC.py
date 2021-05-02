#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

from scipy.sparse import*
f=lambda*z:list(map(int,raw_input().split()))
v,e=f();k=f();a,b,c=list(zip(*map(f,[0]*e)))
x,y=csgraph.dijkstra(csr_matrix((c,(a,b)),[v+1]*2),0,k)
try:print(next(e for e in range(v+1)if x[e]<1<<25 and x[e]==y[e]))
except Exception:print(-1)