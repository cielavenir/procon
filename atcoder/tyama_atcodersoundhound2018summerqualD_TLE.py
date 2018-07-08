#!/usr/bin/python
from __future__ import print_function
import sys,numpy
from scipy.sparse import*
f=lambda*z:map(int,sys.stdin.readline().split())
v,e,s,t=f();a,b,c,d=zip(*map(f,[0]*e))
x,y=[csgraph.dijkstra(csr_matrix((c,(a,b)),[v+1]*2),0,s,limit=1e9)for(c,s)in[(c,s),(d,t)]]
r=[0]*(v+1)
for i in xrange(v-1,-1,-1):r[i]=max(r[i+1],10**15-int(x[i+1]+y[i+1]))
r.pop()
print(*r,sep='\n')
