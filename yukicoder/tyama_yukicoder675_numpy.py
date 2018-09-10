#!/usr/bin/python
import sys,numpy
f=lambda:sys.stdin.readline().split()
n,x,y=map(int,f())
a=[[[1,0,c[1]],[0,1,0],[0,0,1]]if c[0]<2 else [[1,0,0],[0,1,c[1]],[0,0,1]]if c[0]<3 else[[0,1,0],[-1,0,0],[0,0,1]]for c in[[int(e)for e in f()]for _ in[0]*n]]
for i in range(n-2,-1,-1):a[i]=numpy.dot(a[i+1],a[i])
for e in a:print(' '.join(map(str,numpy.dot(e,[x,y,1])[:2])))
