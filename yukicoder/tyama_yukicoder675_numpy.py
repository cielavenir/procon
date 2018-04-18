#!/usr/bin/python
from numpy import*
n,x,y=map(int,raw_input().split())
a=[array([[1,0,c[1]],[0,1,0],[0,0,1]]) if c[0]==1 else array([[1,0,0],[0,1,c[1]],[0,0,1]]) if c[0]==2 else array([[0,1,0],[-1,0,0],[0,0,1]]) for c in [map(int,raw_input().split()) for _ in range(n)]]
for i in range(n-2,-1,-1): a[i]=dot(a[i+1],a[i])
for i in range(n): print ' '.join(map(str,dot(a[i],[x,y,1])[:2]))
