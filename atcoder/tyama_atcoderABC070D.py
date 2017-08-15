#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

from scipy.sparse import*
f=lambda*z:map(int,sys.stdin.readline().split())
n,=f();a,b,c=zip(*map(f,range(n-1)));q,k=f()
z=csgraph.bellman_ford(csr_matrix((c,(a,b)),[n+1]*2),0,k)
for _ in range(q):x,y=f();print int(z[x]+z[y])